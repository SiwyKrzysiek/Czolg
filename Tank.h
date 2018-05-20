#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <list>
#include <SFML/Graphics.hpp>
#include "CircularShape.h"
#include "Projectile.h"

#ifdef _DEBUG
#include <sstream>
#include <iomanip>
#endif

class Tank : public CircularShape
{
private:
	const double bodyRadius;
	const double middleCircleRadius;
	double canonAngle; //Kat lufy w RADIANACH
	double reload;
	sf::Vector2f position;
	sf::RectangleShape canon;
	sf::CircleShape body;
	sf::CircleShape middle;
	sf::Clock clock;

public:
	Tank(const double promien = 100);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const override;
	void update(const sf::Window& window);
	double getCanonAngle() const;
	/**
	 * \brief Zwraca pozycje wylotu lufy
	 * \return Pozycja srodka wylotu lufy
	 */
	sf::Vector2f getMuzzlePosition() const;
	sf::FloatRect getGlobalBounds() const override;
	const sf::Vector2f& getCanonSize() const;
	double getRadius() const override;
	/**
	 * \brief Jesli czolg jest gotowy do strzalu to doda pocisk do listy podanej jako pierwszy argument
	 * \param pociski Lista aktualnie istniejacych pociskow
	 */
	void fire(std::list<Projectile>& pociski);
	double getReloadTime() const;

#ifdef _DEBUG
	std::string getDebugInfo() const;
#endif

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
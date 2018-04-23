#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <list>
#include <SFML/Graphics.hpp>
#include "OkraglyKsztalt.h"
#include "Pocisk.h"

class Czolg : public sf::Drawable, public OkraglyKsztalt //ToDo zaimplementowaæ czas prze³adowania
{
private:
	const double promienCiala;
	const double promienSrodka;
	double katArmaty; //Kat lufy w RADIANACH
	double przeladowanie;
	sf::Vector2f pozycja;
	sf::RectangleShape armata;
	sf::CircleShape cialo;
	sf::CircleShape srodek;
	sf::Clock zegar;

public:
	Czolg(const double promien = 100);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const override;
	void update(const sf::Window& window);
	double getCanonAngle() const;
	sf::Vector2f getMuzzlePosition() const;
	sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getCanonSize() const;
	double getRadius() const override;
	/**
	 * \brief Jesli czolg jest gotowy do strzalu to doda pocisk do 
	 * \param pociski Lista aktualnie istniejacych pociskow
	 */
	void strzel(std::list<Pocisk>& pociski);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
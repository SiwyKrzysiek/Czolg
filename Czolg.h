#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <SFML/Graphics.hpp>
#include "OkraglyKsztalt.h"

class Czolg : public sf::Drawable, public OkraglyKsztalt //ToDo zaimplementowaæ czas prze³adowania
{
private:
	const double promienCiala;
	const double promienSrodka;
	double katArmaty; //K¹t lufy w RADIANACH
	sf::Vector2f pozycja;
	sf::RectangleShape armata;
	sf::CircleShape cialo;
	sf::CircleShape srodek;

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
	//sf::Vector2f getPosition() const override;


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
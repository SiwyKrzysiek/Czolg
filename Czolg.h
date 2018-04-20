#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <SFML/Graphics.hpp>

class Czolg : public sf::Drawable
{
private:
	const double promien;
	const double promienSrodka;
	sf::Vector2f position;
	sf::RectangleShape armata;
	sf::CircleShape cialo;
	sf::CircleShape srodek;

public:
	Czolg(const double promien = 100);
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition() const;
	void update(const sf::Window& window);
	sf::FloatRect getLocalBounds() const;


protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


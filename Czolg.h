#pragma once

#include <SFML/Graphics.hpp>

class Czolg : public sf::Drawable
{
private:
	const double promien;
	const double promienSrodka;
	sf::RectangleShape armata;
	sf::CircleShape cialo;
	sf::CircleShape srodek;

public:
	Czolg();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


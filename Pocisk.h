#pragma once

#include <SFML/Graphics.hpp>
#include "OkraglyKsztalt.h"
#include "Utilities.h"

class Pocisk : public sf::Drawable, public sf::Transformable, public OkraglyKsztalt
{
private:
	sf::CircleShape shape;
	sf::Vector2f speed;

public:
	Pocisk(sf::Vector2f pozycja, double promien, sf::Vector2f predkosc); //ToDo Napisac konstruktor
	void update();
	bool intersects(const OkraglyKsztalt& inny) const;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;
	bool offScreen() const;
	bool operator==(const Pocisk& pocisk) const;
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


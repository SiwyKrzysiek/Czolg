#pragma once

#include <SFML/Graphics.hpp>
#include "CircularShape.h"
#include "Utilities.h"

class Projectile : public sf::Drawable, public sf::Transformable, public CircularShape
{
private:
	sf::CircleShape shape;
	sf::Vector2f speed;

public:
	Projectile(sf::Vector2f pozycja, double promien, sf::Vector2f predkosc); //ToDo Napisac konstruktor
	void update();
	bool intersects(const CircularShape& inny) const;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;
	bool offScreen() const;
	bool operator==(const Projectile& pocisk) const;
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


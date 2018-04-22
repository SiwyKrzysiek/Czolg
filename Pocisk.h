#pragma once

#include <SFML/Graphics.hpp>
#include "OkraglyKsztalt.h"
#include "Utilities.h"

class Pocisk : public sf::Drawable, public sf::Transformable, public OkraglyKsztalt
{
private:
	sf::CircleShape ksztalt;
	sf::Vector2f predkosc;
public:
	Pocisk(); //ToDo Napisac konstruktor
	void update();
	bool intersects(const OkraglyKsztalt& inny) const;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


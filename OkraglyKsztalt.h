#pragma once

#include <SFML/Graphics.hpp>

class OkraglyKsztalt
{
public:
	virtual ~OkraglyKsztalt() = default;
	virtual double getRadius() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
};
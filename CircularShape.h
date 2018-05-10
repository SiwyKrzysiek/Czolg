#pragma once

#include <SFML/Graphics.hpp>

class CircularShape
{
public:
	virtual ~CircularShape() = default;
	virtual double getRadius() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
};
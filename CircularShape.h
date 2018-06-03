#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <math.h>

class CircularShape : public GameObject
{
public:
	virtual ~CircularShape() = default;
	virtual double getRadius() const = 0;
	virtual bool contains(sf::Vector2f point);
};

inline bool CircularShape::contains(sf::Vector2f point)
{
	double a = getPosition().x - point.x;
	double b = getPosition().y - point.y;

	double distance = sqrt(a*a + b * b);

	return distance <= getRadius();
}

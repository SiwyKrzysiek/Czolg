#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Utilities.h"

class CircularShape : public GameObject
{
public:
	virtual ~CircularShape() = default;
	virtual double getRadius() const = 0;
	virtual bool contains(sf::Vector2f point);
};

inline bool CircularShape::contains(sf::Vector2f point)
{
	return distance(point, getPosition()) <= getRadius();
}

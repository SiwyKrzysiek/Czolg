#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class CircularShape : public GameObject
{
public:
	virtual ~CircularShape() = default;
	virtual double getRadius() const = 0;
};
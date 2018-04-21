#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>

class Cel : public sf::Drawable, public sf::Transformable
{
private:
	sf::CircleShape ksztalt;

public:
	Cel();
};

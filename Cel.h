#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Utilities.h"

class Cel : public sf::Drawable, public sf::Transformable
{
private:
	sf::CircleShape ksztalt;

public:
	Cel();
	void update();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

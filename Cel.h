#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "Utilities.h"

class Cel : public sf::Drawable, public sf::Transformable
{
private:
	sf::CircleShape ksztalt;
	sf::Text numer;

public:
	Cel(const sf::Font& font, int numer);
	void update();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

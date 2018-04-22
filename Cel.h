#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "Utilities.h"
#include "OkraglyKsztalt.h"

class Cel : public sf::Drawable, public sf::Transformable, public OkraglyKsztalt
{
private:
	sf::CircleShape ksztalt;
	sf::Text numer;
	void initialize();

public:
	Cel(const sf::Font& font, int numer);
	Cel(const sf::Font& font);
	void setNumber(int numer);
	void update();
	sf::FloatRect getGlobalBounds() const;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

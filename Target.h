#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "Utilities.h"
#include "CircularShape.h"

class Target : public sf::Drawable, public sf::Transformable, public CircularShape
{
private:
	sf::CircleShape shape;
	sf::Text numer;
	void initialize();

public:
	Target(const sf::Font& font, int numer);
	Target(const sf::Font& font);
	void setNumber(int numer);
	void update();
	sf::FloatRect getGlobalBounds() const;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;
	bool intersects(const CircularShape& inny) const;
	/**
	 * \brief Zwraca punkt w obszarze rozgrywki, w ktorym moznaby postawic cel, tak aby nie wystawal poza opszar
	 */
	sf::Vector2f generatePosiblePlacment() const;
	bool operator==(const Target& cel) const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

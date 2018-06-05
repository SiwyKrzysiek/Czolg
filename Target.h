#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "Utilities.h"
#include "CircularShape.h"

class Target : public CircularShape
{
private:
	int myNumber;
	sf::CircleShape shape;
	sf::Text number;
	void initialize();

public:
	Target(const sf::Font& font, int number);
	Target(const sf::Font& font);
	void setNumber(int number);
	int getNumber() const;
	void update();
	sf::FloatRect getGlobalBounds() const override;
	double getRadius() const override;
	sf::Vector2f getPosition() const override;
	bool intersects(const CircularShape& another) const;
	/**
	 * \brief Zwraca punkt w obszarze rozgrywki, w ktorym moznaby postawic cel, tak aby nie wystawal poza opszar
	 */
	sf::Vector2f generatePosiblePlacment() const;
	bool operator==(const Target& target) const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

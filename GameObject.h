#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable, public sf::Transformable
{
public:
	GameObject();
	virtual ~GameObject();

	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
};


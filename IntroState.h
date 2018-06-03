#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "AssetManager.h"

class IntroState : public State //ToDo Dodac obrazek czolgu i przejscie do menu
{
	sf::RenderWindow& window;
	sf::Text title;

public:
	IntroState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "AssetManager.h"

class MainMenueState : public State
{
private:
	sf::RenderWindow& window;
	sf::Sprite playButton;
	sf::Sprite optionsButton;
	sf::Sprite exitButton;

public:
	MainMenueState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


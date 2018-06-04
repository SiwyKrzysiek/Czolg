#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"

class MainMenueState : public State
{
private:
	sf::RenderWindow& window;

public:
	MainMenueState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


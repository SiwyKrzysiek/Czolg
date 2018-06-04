#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"

/**
 * \brief Stan glownego trybu gry
 */
class GameState : public State
{
private:
	sf::RenderWindow& window;

public:
	GameState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


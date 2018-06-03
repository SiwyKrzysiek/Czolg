#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Constants.h"
#include "MissingFileException.h"
#include "AssetManager.h"
#include "StateMachine.h"

class Game
{
private:
	sf::RenderWindow window;

public:
	Game(int width, int height, const std::string& title);

	void run();

};


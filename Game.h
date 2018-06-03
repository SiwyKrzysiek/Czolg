#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.h"

class Game
{
private:
	sf::RenderWindow window;

public:
	Game(int width, int height, const std::string& title);

	void Run();

};


#include "Game.h"

using namespace sf;

Game::Game(int width, int height, const std::string& title)
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(VideoMode(width, height), title, Style::Default, settings);
	window.setFramerateLimit(60);


}

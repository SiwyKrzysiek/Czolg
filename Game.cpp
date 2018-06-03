#include "Game.h"

using namespace sf;
using namespace std;

Game::Game(int width, int height, const std::string& title)
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(VideoMode(width, height), title, Style::Default, settings);
	window.setFramerateLimit(60);

	try
	{
		AssetManager::getInstance().loadFont("Main Font", "tahoma.ttf");
	}
	catch (MissingFileException& e)
	{
		cerr << "Nie udalo sie wczytac czcionki" << endl;
		getchar();
		exit(1);
	}

	//ToDo Dodac pierwszy stan

	run();
}

void Game::run()
{
	while (window.isOpen())
	{
		StateMachine& stateMachine = StateMachine::getInstance();

		stateMachine.processChanges(); //Automat stanow jest synchroniczny

		stateMachine.getActiveState()->handleInput();
		stateMachine.getActiveState()->update();

		stateMachine.getActiveState()->draw();
	}
}

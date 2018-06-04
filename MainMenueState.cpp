#include "MainMenueState.h"

using namespace sf;

MainMenueState::MainMenueState(sf::RenderWindow& window) : window(window)
{

}

void MainMenueState::seteup()
{

}

void MainMenueState::handleInput()
{
	Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		}
	}
}

void MainMenueState::update()
{

}

void MainMenueState::draw()
{
	window.clear();



	window.display();
}

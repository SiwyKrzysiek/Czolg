#include "MainMenueState.h"

using namespace sf;

MainMenueState::MainMenueState(sf::RenderWindow& window) : window(window)
{

}

void MainMenueState::seteup()
{
	AssetManager& assetMenager = AssetManager::getInstance();
	assetMenager.loadTexture("Play Button", "Textures/play button");

	playButton.setTexture(assetMenager.getTexture("Play Button"));
	//playButton.setOrigin(playButton.getGlobalBounds() / 2.0);
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

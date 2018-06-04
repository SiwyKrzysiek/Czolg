#include "MainMenueState.h"

using namespace sf;

MainMenueState::MainMenueState(sf::RenderWindow& window) : window(window)
{

}

void MainMenueState::seteup()
{
	AssetManager& assetMenager = AssetManager::getInstance();
	assetMenager.loadTexture("Play Button", "Textures/play button.png");
	assetMenager.loadTexture("Setting Button", "Textures/settings button.png");
	assetMenager.loadTexture("Exit Button", "Textures/exit button.png");

	playButton.setTexture(assetMenager.getTexture("Play Button"));
	centerOriginInRectangle(playButton);
	playButton.setPosition(window.getSize().x / 2.0, window.getSize().y * 0.234);

	settingsButton.setTexture(assetMenager.getTexture("Setting Button"));
	centerOriginInRectangle(settingsButton);
	settingsButton.setPosition(window.getSize().x / 2.0, playButton.getPosition().y + playButton.getGlobalBounds().height + settingsButton.getGlobalBounds().height*0.2);

	exitButton.setTexture(assetMenager.getTexture("Exit Button"));
	centerOriginInRectangle(exitButton);
	exitButton.setPosition(window.getSize().x / 2.0, settingsButton.getPosition().y + settingsButton.getGlobalBounds().height + settingsButton.getGlobalBounds().height*0.2);
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
		case Event::MouseButtonPressed:
			if (InputMenager::getInstance().isClicked(playButton, window))
			{
				std::cout << "To gramy!" << std::endl;
			}
			if (InputMenager::getInstance().isClicked(settingsButton, window))
			{
				std::cout << "Oto ustawienia" << std::endl;
			}
			if (InputMenager::getInstance().isClicked(exitButton, window))
			{
				window.close();
			}
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

	window.draw(playButton);
	window.draw(settingsButton);
	window.draw(exitButton);

	window.display();
}

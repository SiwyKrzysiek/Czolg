#include "IntroState.h"

using namespace sf;

IntroState::IntroState(sf::RenderWindow& window) : window(window), frame(0)
{
	
}

void IntroState::seteup()
{
	AssetManager& assetMenager = AssetManager::getInstance();
	assetMenager.loadTexture("Tank1", "Textures/czolg1.png");
	assetMenager.loadTexture("Tank2", "Textures/czolg2.png");

	title.setString("Ciezkie zycie czolgisty");
	title.setFont(assetMenager.getFont("Main Font"));
	title.setFillColor(Color::Green);
	title.setCharacterSize(24);
	title.setStyle(Text::Bold);

	title.setPosition(static_cast<double>(window.getSize().x) / 2.0 - 140, window.getSize().y*0.15);

	picture.setTexture(assetMenager.getTexture("Tank1"));
	centerOriginInRectangle(picture);
	picture.setPosition(window.getSize().x / 2.0, window.getSize().y / 2.0);
	
}

void IntroState::handleInput()
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

void IntroState::update()
{
	if (clock.getElapsedTime().asSeconds() > 3)
		;//Todo Przejscie do stanu menue

	static int counter = 0;
	counter++;

	if (counter >= 15)
	{
		counter = 0;

		if (frame == 0) frame = 1; //Sa tylko dwie klatki animacji
		else frame = 0;
	}
	

	switch (frame)
	{
	case 0:
		picture.setTexture(AssetManager::getInstance().getTexture("Tank1"));
		break;
	case 1:
		picture.setTexture(AssetManager::getInstance().getTexture("Tank2"));
		break;
	default:
		picture.setTexture(AssetManager::getInstance().getTexture("Tank1"));
		break;
	}
}

void IntroState::draw()
{
	window.clear();

	window.draw(title);
	window.draw(picture);

	window.display();
}

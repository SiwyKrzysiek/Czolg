#include "IntroState.h"

using namespace sf;

IntroState::IntroState(sf::RenderWindow& window) : window(window)
{
	
}

void IntroState::seteup()
{
	AssetManager& assetMenager = AssetManager::getInstance();

	title.setString("Ciezkie zycie czolgisty");
	title.setFont(assetMenager.getFont("Main Font"));
	title.setFillColor(Color::Green);
	title.setCharacterSize(24);
	title.setStyle(Text::Bold);

	title.setPosition(static_cast<double>(window.getSize().x) / 2.0 - 140, window.getSize().y*0.15);
	
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
}

void IntroState::draw()
{
	window.clear();

	window.draw(title);

	window.display();
}

#include "InputMenager.h"

using namespace sf;

InputMenager::InputMenager()
= default;

bool InputMenager::isClicked(GameObject& object, RenderWindow& window, Mouse::Button button) const
//ToDo Oddzielne sprawdzanie dla OkraglyKsztalt z u¿yciem dynamicznego rzutowania
{
	if (Mouse::isButtonPressed(button))
	{
		try //Gdy obiekt jest okraglym ksztaltem to jest traktowany inaczej
		{
			CircularShape& circularObject = dynamic_cast<CircularShape&>(object);

			return circularObject.contains(static_cast<Vector2f>(Mouse::getPosition(window)));
		}
		catch(std::bad_cast&)
		{
			return object.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window)));
		}
	}

	return false;
}

bool InputMenager::isClicked(sf::Sprite& object, sf::RenderWindow& window, sf::Mouse::Button button) const
{
	return object.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window)));
}

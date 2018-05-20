#include "InputMenager.h"

using namespace sf;

InputMenager::InputMenager()
= default;

bool InputMenager::isClicked(Transformable& object, RenderWindow& window, Mouse::Button button) //ToDo Oddzielne sprawdzanie dla OkraglyKsztalt z u¿yciem dynamicznego rzutowania
{
	if (Mouse::isButtonPressed(button))
	{
		//FloatRect rect(object.ge)
	}

	return false;
}

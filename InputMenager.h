#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "CircularShape.h"

class InputMenager
{
private:
	InputMenager();

public:
	InputMenager(InputMenager& a) = delete;

	static InputMenager& getInstance()
	{
		static InputMenager instance;
		return instance;
	}

	/**
	 * \brief Funkcja sprawdzajaca czy dany obiekt jest klikniety
	 * \param object 
	 * \param window Okno w kturym jest badany obiekt
	 * \param button Ktorym przyciskiem myszy
	 * \return 
	 */
	bool isClicked(GameObject& object, sf::RenderWindow& window, sf::Mouse::Button button = sf::Mouse::Button::Left); //ToDo sprawic by obiekt mogl dac swoj rozmiar


};


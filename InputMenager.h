#pragma once

#include <SFML/Graphics.hpp>

class InputMenager
{
public:
	InputMenager();

	/**
	 * \brief Funkcja sprawdzajaca czy dany obiekt jest klikniety
	 * \param object 
	 * \param window Okno w kturym jest badany obiekt
	 * \param button Ktorym przyciskiem myszy
	 * \return 
	 */
	bool isClicked(sf::Transformable& object, sf::RenderWindow& window, sf::Mouse::Button button = sf::Mouse::Button::Left); //ToDo sprawic by obiekt mogl dac swoj rozmiar


};


#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <iostream>
#include "State.h"
#include "Tank.h"
#include "Target.h"
#include "AssetManager.h"

/**
 * \brief Stan glownego trybu gry
 */
class GameState : public State
{
private:
	const int LICZBA_CELI = 15; //ToDo Wczytanie liczby celow z ustawien
	const double SPACE_AT_TOP = 30;

	int points;
	sf::RenderWindow& window;
	Tank tank;
	std::list<Target> targets;
	std::list<Projectile> projectiles;
	sf::RectangleShape topLine;
	sf::Text info;
	sf::Text score;
	sf::RectangleShape reloadBar;

	void generateTargets();
	/**
	 * \brief Usuwa niepotrzebne pociski i zestrzelone cele
	 */
	void cleanProjectiles();
	void adjustReloadBar();

public:
	GameState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


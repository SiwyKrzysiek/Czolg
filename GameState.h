#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
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

	sf::RenderWindow& window;
	Tank tank;
	std::list<Target> targets;
	std::list<Projectile> projectiles;
	sf::RectangleShape topLine;

	void generateTargets();
	/**
	 * \brief Usuwa niepotrzebne pociski i zestrzelone cele
	 */
	void cleanProjectiles();

public:
	GameState(sf::RenderWindow& window);

	void seteup() override;
	void handleInput() override;
	void update() override;
	void draw() override;
};


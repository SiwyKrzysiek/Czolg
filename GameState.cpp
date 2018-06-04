#include "GameState.h"

using namespace sf;
using namespace std;

GameState::GameState(sf::RenderWindow& window) : window(window)
{

}

void GameState::seteup()
{
	srand(time(nullptr));

	topLine.setSize(Vector2f(window.getSize().x, 0.5));
	topLine.setPosition(0, 30);
	topLine.setFillColor(Color::Red);

	tank.setPosition(300, 300);

	generateTargets();
}

void GameState::handleInput()
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
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				tank.fire(projectiles);
			}
			break;
		}
	}
	
}

void GameState::update()
{
	tank.update(window);

	cleanTargets();
	cleanProjectiles();

	for (Projectile& projectile : projectiles)
		projectile.update();
}

void GameState::draw()
{
	window.clear();

	window.draw(tank);

	for (const Target& target : targets)
		window.draw(target);
	for (const Projectile& projectile : projectiles)
		window.draw(projectile);

	window.draw(topLine);

	window.display();
}

void GameState::generateTargets()
{
	for (int i = 0; i < LICZBA_CELI; i++)
	{
		Target newTarget(AssetManager::getInstance().getFont("Main Font"), i + 1);
		bool correctPlacment = false;

		for (int i = 0; !correctPlacment && i<MAX_FIT_TRIES; i++)
		{
			newTarget.setPosition(newTarget.generatePosiblePlacment());
			correctPlacment = true;

			if (newTarget.intersects(tank))
			{
				correctPlacment = false;
				continue;
			}
			for (const Target& target : targets)
			{
				if (newTarget.intersects(target))
				{
					correctPlacment = false;
					break;
				}
			}
		}
		if (!correctPlacment) break;

		targets.push_back(std::move(newTarget));
	}
}

void GameState::cleanProjectiles()
{
	vector<Projectile> pociskiDoUsuniecia;

	for (Projectile& projectile : projectiles)
	{
		for (Target& target : targets)
		{
			if (projectile.intersects(target))
			{
				pociskiDoUsuniecia.push_back(projectile);
			}
		}

		if (projectile.offScreen())
		{
			pociskiDoUsuniecia.push_back(projectile);
		}
	}

	for (Projectile& pocisk : pociskiDoUsuniecia)
		projectiles.remove(pocisk);
}

void GameState::cleanTargets()
{
	vector<Target> celeDoUsuniecia;

	for (Projectile& projectile : projectiles)
	{
		for (Target& target : targets)
		{
			if (projectile.intersects(target))
			{
				celeDoUsuniecia.push_back(target);
			}
		}
	}

	for (Target& cel : celeDoUsuniecia)
		targets.remove(cel);
}

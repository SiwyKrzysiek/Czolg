#include "GameState.h"

using namespace sf;
using namespace std;

GameState::GameState(sf::RenderWindow& window) : window(window), points(0), tank(90)
{

}

void GameState::seteup()
{
	srand(time(nullptr));

	topLine.setSize(Vector2f(window.getSize().x, 0.8));
	topLine.setPosition(0, SPACE_AT_TOP + topLine.getSize().y);
	topLine.setFillColor(Color::Red);

	info.setFont(AssetManager::getInstance().getFont("Main Font"));
	info.setFillColor(Color::White);
	info.setCharacterSize(23);
	info.setPosition(0, 0);
	info.setString("Shot as many targets as you can!");

	score.setFont(AssetManager::getInstance().getFont("Main Font"));
	score.setFillColor(Color::White);
	score.setCharacterSize(23);
	score.setPosition(info.getGlobalBounds().width + window.getSize().x*0.2, 0);
	score.setString("Score: " + to_string(points));

	reloadBar.setFillColor(Color::Green);
	reloadBar.setSize(Vector2f(window.getSize().x*0.017, SPACE_AT_TOP*0.33));
	reloadBar.setOrigin(0, reloadBar.getSize().y);
	reloadBar.setPosition(window.getSize().x*0.99 - reloadBar.getSize().x, SPACE_AT_TOP);

	tank.setPosition(300, 300);
	

	generateTargets();
}

void GameState::handleInput()
{
	static bool inputFromPreviousState = true;

	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::MouseButtonReleased:
			inputFromPreviousState = false;
			break;
		}
	}
	
	if (Mouse::isButtonPressed(Mouse::Left) && !inputFromPreviousState)
	{
		tank.fire(projectiles);
	}
}

void GameState::update()
{
	tank.update(window);

	cleanProjectiles();

	for (Projectile& projectile : projectiles)
		projectile.update();

	adjustReloadBar();

	#ifdef PRINT_ANGLE_AND_REALOAD_TIME
	#ifdef _DEBUG
			cout << tank.getDebugInfo() << endl;
	#endif
	#endif
}

void GameState::draw()
{
	window.clear();

	window.draw(tank);

	for (const Target& target : targets)
		window.draw(target);
	for (const Projectile& projectile : projectiles)
		window.draw(projectile);

	window.draw(reloadBar);
	window.draw(topLine);
	window.draw(info);
	window.draw(score);

	window.display();
}

void GameState::adjustReloadBar()
{
	double newHeight = (tank.getReloadTime() / tank.getMaxReloadTime()) * SPACE_AT_TOP;

	reloadBar.setSize(Vector2f(reloadBar.getSize().x, newHeight));
	reloadBar.setOrigin(0, reloadBar.getSize().y);
	reloadBar.setPosition(window.getSize().x*0.99 - reloadBar.getSize().x, SPACE_AT_TOP);
}

void GameState::generateTargets()
{
	for (int i = 0; i < LICZBA_CELI; i++)
	{
		Target newTarget(AssetManager::getInstance().getFont("Main Font"), rand() % 99 + 1);
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
	vector<Target> celeDoUsuniecia;

	for (Projectile& projectile : projectiles)
	{
		for (Target& target : targets)
		{
			if (projectile.intersects(target))
			{
				pociskiDoUsuniecia.push_back(projectile);
				celeDoUsuniecia.push_back(target);
			}
		}

		if (projectile.offScreen())
		{
			pociskiDoUsuniecia.push_back(projectile);
		}
	}

	for (Projectile& pocisk : pociskiDoUsuniecia)
		projectiles.remove(pocisk);

	for (Target& cel : celeDoUsuniecia)
		targets.remove(cel);
}

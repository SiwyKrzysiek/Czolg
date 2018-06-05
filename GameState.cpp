#include "GameState.h"

using namespace sf;
using namespace std;

GameState::GameState(sf::RenderWindow& window,const int targetCount) : window(window), points(0), tank(RELOAD_TIME_IN_SECONDS ,90),
active(true), TARGET_COUNT(targetCount), roundTime(20), timeLeft(roundTime)
{

}

void GameState::seteup()
{
	srand(time(nullptr));

	const int charaterSize = 23;

	topLine.setSize(Vector2f(window.getSize().x, 0.8));
	topLine.setPosition(0, SPACE_AT_TOP + topLine.getSize().y);
	topLine.setFillColor(Color::Red);

	info.setFont(AssetManager::getInstance().getFont("Main Font"));
	info.setFillColor(Color::White);
	info.setCharacterSize(charaterSize);
	info.setPosition(0, 0);
	info.setString("Shot as many targets as you can!");

	score.setFont(AssetManager::getInstance().getFont("Main Font"));
	score.setFillColor(Color::White);
	score.setCharacterSize(charaterSize);
	score.setPosition(info.getPosition().x + info.getGlobalBounds().width + window.getSize().x*0.09, 0);
	score.setString("Score: " + to_string(points));

	timeLeftInfo.setFont(AssetManager::getInstance().getFont("Main Font"));
	timeLeftInfo.setFillColor(Color::White);
	timeLeftInfo.setCharacterSize(charaterSize);
	timeLeftInfo.setPosition(score.getPosition().x + score.getGlobalBounds().width + window.getSize().x*0.07, 0);
	timeLeftInfo.setString("Time left: " + to_string(static_cast<int>(timeLeft)));

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
		case Event::KeyReleased:
			if (!active)
				StateMachine::getInstance().add(std::unique_ptr<State>(std::make_unique<MainMenueState>(window)));
			break;
		}
	}
	
	if (Mouse::isButtonPressed(Mouse::Left) && !inputFromPreviousState && active)
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

	score.setString("Score: " + to_string(points));

	if (timeLeft > 0)
	{
		timeLeft = roundTime - clock.getElapsedTime().asSeconds();
		if (timeLeft < 0)
		{
			timeLeft = 0;
			active = false;
			info.setString("Press any key to return to menu");
		}
	}
	timeLeftInfo.setString("Time left: " + to_string(static_cast<int>(timeLeft)));
	

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
	window.draw(timeLeftInfo);

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
	for (int i = 0; i < TARGET_COUNT; i++)
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
	vector<Projectile> projectilesToRemove;
	vector<Target> targetsToRemove;

	for (Projectile& projectile : projectiles)
	{
		for (Target& target : targets)
		{
			if (projectile.intersects(target))
			{
				projectilesToRemove.push_back(projectile);
				targetsToRemove.push_back(target);
			}
		}

		if (projectile.offScreen())
		{
			projectilesToRemove.push_back(projectile);
		}
	}

	for (Projectile& projectile : projectilesToRemove)
		projectiles.remove(projectile);

	for (Target& target : targetsToRemove)
	{
		points += target.getNumber();
		targets.remove(target);
	}
}

#define _USE_MATH_DEFINES //Test test

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "Constants.h"
#include "Tank.h"
#include "Utilities.h"
#include "Target.h"
#include "Projectile.h"
#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "Ciezkie zycie czolgisty");
	game.run();

	return 0;
}

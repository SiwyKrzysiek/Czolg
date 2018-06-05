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

//	const int LICZBA_CELI = 15;
//
//	//czcionka i tekst u gory
//	Text text;
//	text.setFont(font);
//	string ile = to_string(LICZBA_CELI);
//	Text liczba;
//	liczba.setFont(font);
//	liczba.setCharacterSize(28);
//	liczba.setString(ile);
//	liczba.setPosition(sf::Vector2f(170, 0));
//	text.setString("Liczba kulek: ");
//	text.setCharacterSize(28);
//	text.setFillColor(sf::Color::White);

//
//		//Wypisanie liczby celi na ekranie
//		liczba.setString(to_string(cele.size()));
//
//
//		window.draw(text);
//		window.draw(liczba);


	return 0;
}

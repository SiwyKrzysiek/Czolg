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

#include "Stale.h"
#include "Tank.h"
#include "Utilities.h"
#include "Target.h"
#include "Projectile.h"

using namespace sf;
using namespace std;

int main()
{
	srand(time(nullptr));


	//render i ustawienia
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gra w strzelanie kolorowa kulka", Style::Default, settings);
	window.setFramerateLimit(60);

	Font font;
	if (!font.loadFromFile("tahoma.ttf"))
	{
		cerr << "Nie udalo sie wczytac czcionki" << endl;
		getchar();
		exit(1);
	}

	Tank czolg;
	czolg.setPosition(300, 300);

	const int LICZBA_CELI = 15;

	//czcionka i tekst u gory
	Text text;
	text.setFont(font);
	string ile = to_string(LICZBA_CELI);
	Text liczba;
	liczba.setFont(font);
	liczba.setCharacterSize(28);
	liczba.setString(ile);
	liczba.setPosition(sf::Vector2f(170, 0));
	text.setString("Liczba kulek: ");
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::White);

	//Utworzenie celi
	list<Target> cele;
	for (int i = 0; i < LICZBA_CELI; i++) //ToDo Zamienic na funkcje
	{
		Target nowyCel(font, i + 1);
		bool prawdlowaPozycja = false;

		for (int i=0; !prawdlowaPozycja && i<MAX_FIT_TRIES; i++)
		{
			nowyCel.setPosition(nowyCel.generatePosiblePlacment());
			prawdlowaPozycja = true;

			if (nowyCel.intersects(czolg))
			{
				prawdlowaPozycja = false;
				continue;
			}
			for (const Target& cel : cele)
			{
				if (nowyCel.intersects(cel))
				{
					prawdlowaPozycja = false;
					break;
				}
			}
		}
		if (!prawdlowaPozycja) break;

		cele.push_back(move(nowyCel));
	}

	//linia u gory ekranu
	RectangleShape linia(Vector2f(800, 0.5));
	linia.setPosition(0, 30);
	linia.setFillColor(Color::Red);

	//Lista akatualnie lec¹cych pocisków
	list<Projectile> pociski;
	
	//otwiera sie okienko
	while (window.isOpen())
	{
		//zamkniecie okna
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		//wypisanie kata i czasu przeladowania
#ifdef PRINT_ANGLE_AND_REALOAD_TIME
#ifdef _DEBUG
		cout << czolg.getDebugInfo() << endl;
#endif
#endif

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			czolg.fire(pociski);
		}

		//rysowanie
		window.clear();

		//Wypisanie liczby celi na ekranie
		liczba.setString(to_string(cele.size()));

		czolg.update(window);
		window.draw(czolg);

		vector<Projectile> pociskiDoUsuniecia;
		vector<Target> celeDoUsuniecia;
		for (Projectile& pocisk : pociski)
		{
			for (Target& cel : cele)
			{
				if (pocisk.intersects(cel))
				{
					pociskiDoUsuniecia.push_back(pocisk);
					celeDoUsuniecia.push_back(cel);
				}
			}

			if (pocisk.offScreen())
			{
				pociskiDoUsuniecia.push_back(pocisk);
			}
		}
		for (Projectile& pocisk : pociskiDoUsuniecia)
			pociski.remove(pocisk);
		for (Target& cel : celeDoUsuniecia)
			cele.remove(cel);

		for (Projectile& pocisk : pociski)
			pocisk.update();

		for (const Target& cel : cele)
			window.draw(cel);
		for (const Projectile& pocisk : pociski)
			window.draw(pocisk);

		window.draw(text);
		window.draw(liczba);
		window.draw(linia);

		window.display();
	}

	return 0;
}

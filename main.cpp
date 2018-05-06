#define _USE_MATH_DEFINES //Test

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
#include "Czolg.h"
#include "Utilities.h"
#include "Cel.h"
#include "Pocisk.h"

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

	Czolg czolg;
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
	list<Cel> cele;
	for (int i = 0; i < LICZBA_CELI; i++) //ToDo Zamienic na funkcje
	{
		Cel nowyCel(font, i + 1);
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
			for (const Cel& cel : cele)
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
	list<Pocisk> pociski;
	
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
			czolg.strzel(pociski);
		}

		//rysowanie
		window.clear();

		//Wypisanie liczby celi na ekranie
		liczba.setString(to_string(cele.size()));

		czolg.update(window);
		window.draw(czolg);

		vector<Pocisk> pociskiDoUsuniecia;
		vector<Cel> celeDoUsuniecia;
		for (Pocisk& pocisk : pociski)
		{
			for (Cel& cel : cele)
			{
				if (pocisk.intersects(cel))
				{
					pociskiDoUsuniecia.push_back(pocisk);
					celeDoUsuniecia.push_back(cel);
				}
			}

			if (pocisk.pozaEkranem())
			{
				pociskiDoUsuniecia.push_back(pocisk);
			}
		}
		for (Pocisk& pocisk : pociskiDoUsuniecia)
			pociski.remove(pocisk);
		for (Cel& cel : celeDoUsuniecia)
			cele.remove(cel);

		for (Pocisk& pocisk : pociski)
			pocisk.update();

		for (const Cel& cel : cele)
			window.draw(cel);
		for (const Pocisk& pocisk : pociski)
			window.draw(pocisk);

		window.draw(text);
		window.draw(liczba);
		window.draw(linia);

		window.display();
	}

	return 0;
}

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

#if 0
	//promien czolgu
	int r = 100;

	//definicje i pparametry czolgu
	CircleShape cialo(r, 70);
	RectangleShape armata(Vector2f(1.5*r, 0.5*r));
	cialo.setPosition(300 - (0.5*r), 300 - (0.5*r));
	cialo.setOrigin(r, r);
	cialo.setFillColor(Color::Red);
	armata.setFillColor(Color::Blue);
	armata.setPosition(cialo.getPosition());
	armata.setOrigin(0, 0.25*r); //Ustawia srodek armaty w polowie krotszej krawedzi

	CircleShape male;
	male.setRadius(0.4*r);
	male.setPosition(cialo.getPosition());
	male.setOrigin(0.4*r, 0.4*r);
	cialo.setOutlineThickness(-5);
	cialo.setOutlineColor(Color::White);
	armata.setOutlineThickness(-5);
	armata.setOutlineColor(Color::White);
	male.setOutlineThickness(-5);
	male.setOutlineColor(Color::Black);
#endif

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

	//PRZEJSCIE NA CELE!
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

	//czas
	Clock clock;

	//Przejscie na nowe pociski
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
			//if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
			//	window.close();
		}

		//wypisanie kata i czasu przeladowania
//#ifdef PRINT_ANGLE_AND_REALOAD_TIME //ToDO Naprawic logowanie kata i czasu przeladowania
//		std::cout << czolg.getCanonAngle() * 180 / M_PI << "\t\t";
//		if (reload.asSeconds() > 3)
//		{
//			std::cout << "Do strzalu: 0\n";
//		}
//		else if (reload.asSeconds() < 3)
//		{
//			std::cout << "Do strzalu: " << (3 - reload.asSeconds()) << "\n";
//		}
//#endif

		//Nowa wersja strzalu
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			czolg.strzel(pociski);
		}

		//rysowanie
		window.clear();

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

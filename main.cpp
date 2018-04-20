#define _USE_MATH_DEFINES //Test

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include<vector>

#include "Czolg.h"

using namespace sf;
using namespace std;

template <class T>
string toString(const T& t)
{
	stringstream ss;
	ss << t;
	string tmp;
	ss >> tmp;

	return tmp;
}

inline double rootSumSquared(int a, int b)
{
	return sqrt(a*a + b*b);
}

inline Color randomColor()
{
	return Color(rand() % 250 + 5, rand() % 250 + 5, rand() % 250 + 5);
}

double distance (Transformable a, Transformable b)
{
	return rootSumSquared(a.getPosition().x-b.getPosition().x, a.getPosition().y-b.getPosition().y);
}


int main()
{


	srand(time(NULL));

	//render i ustawienia
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "Gra w strzelanie kolorowa kulka", Style::Default, settings);
	window.setFramerateLimit(60);

#if 1
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

	//ilosc kulek
	const int LICZBA_KULEK = 10;

	//czcionka i tekst u gory
	Font font;
	if (!font.loadFromFile("tahoma.ttf"))
	{
		cerr << "Popsute" << endl;
		getchar();
		exit(1);
	}
	Text text;
	text.setFont(font);
	string ile = to_string(LICZBA_KULEK);
	Text liczba;
	liczba.setFont(font);
	liczba.setCharacterSize(28);
	liczba.setString(ile);
	liczba.setPosition(sf::Vector2f(170, 0));
	text.setString("Liczba kulek: ");
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::White);

	//definicja i parametry kulek
	sf::CircleShape kulki[LICZBA_KULEK];
	for (CircleShape& z : kulki)
	{
		z.setRadius(rand() % 25 + 25);
		z.setFillColor(randomColor());
		z.setOutlineColor(randomColor());
		z.setOutlineThickness(-2);
	}

	//losowanie pozycji kulek
	int xpos[LICZBA_KULEK], ypos[LICZBA_KULEK];
	for (int z = 0; z < LICZBA_KULEK; z++)
	{
		xpos[z] = rand() % 750;
		ypos[z] = rand() % 500 + 30;
	}

	//sprawdzenie odleglosci kulek od czolgu
	for (int z = 0; z < LICZBA_KULEK; z++)
	{
		double dl = 0;
		while (dl < czolg.getLocalBounds().width / 2) //Zmiana na u¿ycie klasy czo³g
		{
			int xt = xpos[z] + kulki[z].getRadius(); //Dlaczego dodaje sie promien?
			int yt = ypos[z] + kulki[z].getRadius();

			//dl = pow((cialo.getPosition().x - xt), 2); //pow slabo dziala na intach
			//dl += pow((cialo.getPosition().y - yt), 2);
			//dl = sqrt(dl);
			//dl = sqrt((cialo.getPosition().x - xt)*(cialo.getPosition().x - xt) + (cialo.getPosition().y - yt)*(cialo.getPosition().y - yt));

			dl = rootSumSquared(czolg.getPosition().x - xt, czolg.getPosition().y - yt); //TODO: Liczyc odleglosc mniedzy obiektami

			dl -= kulki[z].getRadius(); //Zeby nie wszedl krawedzia na czolg
			if (dl < czolg.getLocalBounds().width)
			{
				xpos[z] = rand() % 750;
				ypos[z] = rand() % 500 + 30;
			}
		}

		//sprawdzenie czy kulki sie nakladaja
		double odl = 0;
		for (int c = 0; c < z; c++) //Dla kazdej wczesniejszej kulki
		{
			double sumaPromieni = kulki[c].getRadius() + kulki[z].getRadius();

			int xz = xpos[z] + kulki[z].getRadius(); //X srodka aktualnej kulki
			int xc = xpos[c] + kulki[c].getRadius(); //X srodka wczesniejszej kulki
			int yz = ypos[z] + kulki[z].getRadius(); //Y srodka aktualnej kulki
			int yc = ypos[c] + kulki[c].getRadius(); //Y srodka wczesniejszej kulki

			//rr += kulki[z].getRadius();
			//odl = pow((xz - xc), 2);
			//odl += pow((yc - yz), 2);
			//odl = sqrt(odl);
			odl = rootSumSquared(xz - xc, yc - yz);

			if (odl < sumaPromieni)
			{
				xpos[z] = rand() % 750;
				ypos[z] = rand() % 500 + 30;
				z--;
				break;
			}
		}
	}

	//ustawienie ostatecznej pozycji kulek
	for (int z = 0; z < LICZBA_KULEK; z++)
	{
		kulki[z].setPosition(xpos[z], ypos[z]);
	}

	//numerowanie kulek
	sf::Text numery[LICZBA_KULEK];
	for (int z = 0; z < LICZBA_KULEK; z++)
	{
		std::string numer = to_string(z+1);
		numery[z].setFont(font);
		numery[z].setString(numer);
		numery[z].setCharacterSize(kulki[z].getRadius()*1.5);
		numery[z].setFillColor(sf::Color::White);
		numery[z].setOutlineColor(sf::Color::Black);
		numery[z].setOutlineThickness(2);
		numery[z].setPosition(kulki[z].getPosition().x + (z<9 ? (kulki[z].getRadius()*0.5) : 0), kulki[z].getPosition().y);
	}

	//linia u gory ekranu
	RectangleShape linia(Vector2f(800, 0.5));
	linia.setPosition(0, 30);
	linia.setFillColor(Color::Red);

	//pocisk
	CircleShape pocisk;
	pocisk.setFillColor(Color::Red);
	pocisk.setRadius(czolg.getCanonSize().y / 5);
	pocisk.setPosition(-100, -100);
	pocisk.setOrigin(pocisk.getRadius(), pocisk.getRadius());

	//zmienna pomocniczna
	int pociskLeci = 0;

	//czas
	Clock clock;
	//Time reload;


	//otwiera sie okienko
	while (window.isOpen())
	{
		//czas przeladowania
		Time reload = clock.getElapsedTime();

		//obrot lufy
		Vector2f position = Vector2f(Mouse::getPosition(window));
		float a = position.x - armata.getPosition().x, b = position.y - armata.getPosition().y;
		float deg = atan2(b, a) * 180 / M_PI; //Policzenie kata lufy

		armata.setRotation(deg);

		//zamkniecie okna
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
			//	window.close();
		}

		//wypisanie kata i czasu przeladowania
		std::cout << deg << "\t\t";
		if (reload.asSeconds() > 3)
		{
			std::cout << "Do strzalu: 0\n";
		}
		else if (reload.asSeconds() < 3)
		{
			std::cout << "Do strzalu: " << (3 - reload.asSeconds()) << "\n";
		}

		//kierunek i wektor strzalu
		float f = 10; //Predkosc pocisku
		//Vector2f kierunek = Vector2f(cos(atan2(b, a))*armata.getSize().x, sin(atan2(b, a))*armata.getSize().x)*f;
		static Vector2f kierunek;

		//strzal
		if (pociskLeci == 0 && reload.asSeconds()>3) //Todo Zrobiæ by to Czo³g sztrzela³
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				kierunek = Vector2f(cos(atan2(b, a)), sin(atan2(b, a)))*f;

				pocisk.setPosition(armata.getPosition().x + (cos(atan2(b, a))*armata.getSize().x), armata.getPosition().y + (sin(atan2(b, a))*armata.getSize().x));
				pociskLeci = 1;
			}
		}
		if (pociskLeci == 1)
		{
			pocisk.move(kierunek);
			clock.restart();
		}

		
		if  (	pocisk.getPosition().x <= -pocisk.getRadius() || //pocisk wychodzi poza lewa krawedz ekranu
				pocisk.getPosition().y <= pocisk.getRadius() + 30 || //pocisk wychodzi poza gorna krawedz ekranu
				pocisk.getPosition().y >= window.getSize().y - pocisk.getRadius() || //pocisk wychodzi poza dolna krawedz ekranu
				pocisk.getPosition().x >= window.getSize().x - pocisk.getRadius() //pocisk wychodzi poza prawa krawedz ekranu
			)
		{
			//pocisk.setPosition(-100, -100);
			pociskLeci = 0;
		}

		
		//else if (pocisk.getPosition().y <= pocisk.getRadius() + 30)
		//{
		//	pocisk.setPosition(-100, -100);
		//	pociskLeci = 0;
		//}

		//
		//else if (pocisk.getPosition().y >= window.getSize().y - pocisk.getRadius())
		//{
		//	pocisk.setPosition(-100, -100);
		//	pociskLeci = 0;
		//}

		////pocisk wychodzi poza prawa krawedz ekranu
		//else if (pocisk.getPosition().x >= window.getSize().x - pocisk.getRadius())
		//{
		//	pocisk.setPosition(-100, -100);
		//	pociskLeci = 0;
		//}

		//pocisk uderza w cel
		for (int z = 0; z < LICZBA_KULEK; z++)
		{
			if (pocisk.getGlobalBounds().intersects(kulki[z].getGlobalBounds()))
			{
				kulki[z].setPosition(2000, 2000);
				pocisk.setPosition(-100, -100);
				pociskLeci = 0;
				numery[z].setPosition(2000, 2000);
			}
		}

		//rysowanie
		window.clear();


		czolg.update(window);

		window.draw(czolg);
		//window.draw(cialo);
		//window.draw(armata);
		//window.draw(male);
		for (int z = 0; z < LICZBA_KULEK; z++)
		{
			window.draw(kulki[z]);
			window.draw(numery[z]);
		}
		window.draw(pocisk);
		window.draw(text);
		window.draw(liczba);
		window.draw(linia);
		window.display();
	}

	return 0;
}

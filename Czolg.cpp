#include "Czolg.h"

using namespace sf;

Czolg::Czolg(const double promien) : position(0.f, 0.f),
promien(promien),
promienSrodka(0.4*promien),
armata(Vector2f(1.5*promien, 0.5*promien)),
cialo(promien, 70),
srodek(promienSrodka, 60)
{
	//Przygotowanie ciala
	//cialo.setPosition(300 - (0.5*promien), 300 - (0.5*promien));
	cialo.setPosition(position);
	cialo.setOrigin(promien, promien);
	cialo.setFillColor(Color::Red);
	cialo.setOutlineThickness(-5.0f);
	cialo.setOutlineColor(Color::White);

	//Przygotowanie armaty
	armata.setFillColor(Color::Blue);
	armata.setPosition(cialo.getPosition());
	armata.setOrigin(0, 0.25*promien);
	armata.setOutlineThickness(-5.0f);
	armata.setOutlineColor(Color::White);

	//Przygotowanie srodka
	srodek.setPosition(cialo.getPosition());
	srodek.setOrigin(promienSrodka, promienSrodka);
	srodek.setOutlineThickness(-5.0f);
	srodek.setOutlineColor(Color::Black);
}

void Czolg::setPosition(float x, float y)
{
	position = Vector2f(x - 0.5*promien, y - 0.5*promien);

	cialo.setPosition(position);
	armata.setPosition(position);
	srodek.setPosition(position);
}

void Czolg::update(const sf::Window& window)
{
	Vector2f mousePosition(Mouse::getPosition(window));
	Vector2f a = mousePosition - armata.getPosition();

	double katLufy = atan2(a.y, a.x) * 180 / M_PI;

	armata.setRotation(katLufy);
}

void Czolg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cialo, states);
	target.draw(armata, states);
	target.draw(srodek, states);
}

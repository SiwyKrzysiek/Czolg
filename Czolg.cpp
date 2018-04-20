#include "Czolg.h"

using namespace sf;

Czolg::Czolg() : promien(100),
promienSrodka(0.4*promien),
armata(Vector2f(1.5*promien, 0.5*promien)),
cialo(promien, 70),
srodek(promienSrodka, 60)
{
	//Przygotowanie ciala
	cialo.setPosition(300 - (0.5*promien), 300 - (0.5*promien));
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

void Czolg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cialo, states);
	target.draw(armata, states);
	target.draw(srodek, states);
}

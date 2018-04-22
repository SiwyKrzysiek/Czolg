#include "Czolg.h"

using namespace sf;

Czolg::Czolg(const double promien) : pozycja(0.f, 0.f),
promienCiala(promien),
promienSrodka(0.4*promien),
katArmaty(0.0),
armata(Vector2f(1.5*promien, 0.5*promien)),
cialo(promien, 70),
srodek(promienSrodka, 60)
{
	//Przygotowanie ciala
	//cialo.setPosition(300 - (0.5*promienCiala), 300 - (0.5*promienCiala)); //Todo Spyta� Ma�ka dlaczego tak jest
	cialo.setPosition(pozycja);
	cialo.setOrigin(promien, promien);
	cialo.setFillColor(Color::Red);
	cialo.setOutlineThickness(-5.0f);
	cialo.setOutlineColor(Color::White);

	//Przygotowanie armaty
	armata.setFillColor(Color::Blue);
	armata.setPosition(cialo.getPosition());
	armata.setOrigin(0, armata.getSize().y/2.0);
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
	pozycja = Vector2f(x, y);

	cialo.setPosition(pozycja);
	armata.setPosition(pozycja);
	srodek.setPosition(pozycja);
}

sf::Vector2f Czolg::getPosition() const
{
	return  pozycja;
}

void Czolg::update(const sf::Window& window)
{
	Vector2f a = static_cast<Vector2f>(Mouse::getPosition(window)) - armata.getPosition();

	katArmaty = atan2(a.y, a.x);

	armata.setRotation(katArmaty * 180 / M_PI);
}

double Czolg::getCanonAngle() const
{
	return katArmaty;
}

/**
 * \brief Zwraca pozycje wylotu lufy czo�gu
 */
sf::Vector2f Czolg::getMuzzlePosition() const
{
	return Vector2f{pozycja + Vector2f(cos(katArmaty), sin(katArmaty))*armata.getSize().x };
}

sf::FloatRect Czolg::getGlobalBounds() const
{
	return  FloatRect{ getPosition(), Vector2f(armata.getSize().x, armata.getSize().x)*2.0f };
}

const sf::Vector2f& Czolg::getCanonSize() const
{
	return armata.getSize();
}

double Czolg::getRadius() const
{
	return armata.getSize().x;
}

void Czolg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cialo, states);
	target.draw(armata, states);
	target.draw(srodek, states);
}

#include "Czolg.h"

using namespace sf;

Czolg::Czolg(const double promien) : position(0.f, 0.f),
promien(promien),
promienSrodka(0.4*promien),
katLufy(0.0),
armata(Vector2f(1.5*promien, 0.5*promien)),
cialo(promien, 70),
srodek(promienSrodka, 60)
{
	//Przygotowanie ciala
	//cialo.setPosition(300 - (0.5*promien), 300 - (0.5*promien)); //Todo Spytaæ Maæka dlaczego tak jest
	cialo.setPosition(position);
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
	position = Vector2f(x - 0.5*promien, y - 0.5*promien);

	cialo.setPosition(position);
	armata.setPosition(position);
	srodek.setPosition(position);
}

const sf::Vector2f& Czolg::getPosition() const
{
	return  position;
}

void Czolg::update(const sf::Window& window)
{
	Vector2f a = static_cast<Vector2f>(Mouse::getPosition(window)) - armata.getPosition();

	katLufy = atan2(a.y, a.x);

	armata.setRotation(katLufy * 180 / M_PI);
}

sf::FloatRect Czolg::getLocalBounds() const
{
	return  FloatRect{ getPosition(), Vector2f(armata.getSize().x, armata.getSize().x)*2.0f };
}

const sf::Vector2f& Czolg::getCanonSize() const
{
	return armata.getSize();
}

void Czolg::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cialo, states);
	target.draw(armata, states);
	target.draw(srodek, states);
}

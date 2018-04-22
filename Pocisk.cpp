#include "Pocisk.h"

using namespace sf;

Pocisk::Pocisk(sf::Vector2f pozycja, double promien, sf::Vector2f predkosc) : ksztalt(promien), predkosc(predkosc)
{
	setPosition(pozycja);

	ksztalt.setOrigin(promien, promien);
	ksztalt.setFillColor(Color::Red);
	ksztalt.setPosition(Pocisk::getPosition());
}

void Pocisk::update()
{
	move(predkosc);
	ksztalt.setPosition(getPosition());
}

bool Pocisk::pozaEkranem() const
{
	return (
		getPosition().x <= getRadius() || //pocisk wychodzi poza lewa krawedz ekranu
		getPosition().y <= getRadius() + SCREEN_HEIGHT - GAMEPLAY_AREA_HEIGHT || //pocisk wychodzi poza gorna krawedz ekranu
		getPosition().y >= SCREEN_HEIGHT - getRadius() || //pocisk wychodzi poza dolna krawedz ekranu
		getPosition().x >= GAMEPLAY_AREA_WIDTH - getRadius() //pocisk wychodzi poza prawa krawedz ekranu
		);
}

bool Pocisk::operator==(const Pocisk& pocisk) const
{
	return (
		pocisk.getPosition() == getPosition() &&
		pocisk.getRadius() == getRadius() &&
		pocisk.predkosc == predkosc
		);

}

bool Pocisk::intersects(const OkraglyKsztalt& inny) const
{
	return intersect(*this, inny);
}

double Pocisk::getRadius() const
{
	return ksztalt.getRadius();
}

sf::Vector2f Pocisk::getPosition() const
{
	return Transformable::getPosition();
}

void Pocisk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(ksztalt);
}

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

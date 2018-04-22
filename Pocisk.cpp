#include "Pocisk.h"

using namespace sf;

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

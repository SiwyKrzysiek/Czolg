#include "Cel.h"

using namespace sf;

Cel::Cel() : ksztalt(rand() % 25 + 25)
{
	ksztalt.setFillColor(randomColor());
	ksztalt.setOutlineColor(randomColor());
	ksztalt.setOutlineThickness(-2);
	ksztalt.setOrigin(ksztalt.getRadius(), ksztalt.getRadius());

	//setOrigin(ksztalt.getRadius(), ksztalt.getRadius());
}

void Cel::update()
{
	ksztalt.setPosition(getPosition());
}

void Cel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const_cast<Cel*>(this)->update();

	target.draw(ksztalt);
}

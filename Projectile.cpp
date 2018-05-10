#include "Projectile.h"

using namespace sf;

Projectile::Projectile(sf::Vector2f pozycja, double promien, sf::Vector2f predkosc) : shape(promien), speed(predkosc)
{
	setPosition(pozycja);

	shape.setOrigin(promien, promien);
	shape.setFillColor(Color::Red);
	shape.setPosition(Projectile::getPosition());
}

void Projectile::update()
{
	move(speed);
	shape.setPosition(getPosition());
}

bool Projectile::offScreen() const
{
	return (
		getPosition().x <= getRadius() || //pocisk wychodzi poza lewa krawedz ekranu
		getPosition().y <= getRadius() + SCREEN_HEIGHT - GAMEPLAY_AREA_HEIGHT || //pocisk wychodzi poza gorna krawedz ekranu
		getPosition().y >= SCREEN_HEIGHT - getRadius() || //pocisk wychodzi poza dolna krawedz ekranu
		getPosition().x >= GAMEPLAY_AREA_WIDTH - getRadius() //pocisk wychodzi poza prawa krawedz ekranu
		);
}

bool Projectile::operator==(const Projectile& pocisk) const
{
	return (
		pocisk.getPosition() == getPosition() &&
		pocisk.getRadius() == getRadius() &&
		pocisk.speed == speed
		);

}

bool Projectile::intersects(const CircularShape& inny) const
{
	return intersect(*this, inny);
}

double Projectile::getRadius() const
{
	return shape.getRadius();
}

sf::Vector2f Projectile::getPosition() const
{
	return Transformable::getPosition();
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

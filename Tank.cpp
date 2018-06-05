#include "Tank.h"
#include <iostream>

using namespace sf;

Tank::Tank(const double radius) : position(0.f, 0.f),
bodyRadius(radius),
middleCircleRadius(0.4*radius),
canonAngle(0.0),
reload(0.0),
canon(Vector2f(1.5*radius, 0.5*radius)),
body(radius, 70),
middle(middleCircleRadius, 60)
{
	//Przygotowanie ciala
	body.setPosition(position);
	body.setOrigin(radius, radius);
	body.setFillColor(Color::Red);
	body.setOutlineThickness(-5.0f);
	body.setOutlineColor(Color::White);

	//Przygotowanie armaty
	canon.setFillColor(Color::Blue);
	canon.setPosition(body.getPosition());
	canon.setOrigin(0, canon.getSize().y/2.0);
	canon.setOutlineThickness(-5.0f);
	canon.setOutlineColor(Color::White);

	//Przygotowanie srodka
	middle.setPosition(body.getPosition());
	middle.setOrigin(middleCircleRadius, middleCircleRadius);
	middle.setOutlineThickness(-5.0f);
	middle.setOutlineColor(Color::Black);
}

void Tank::setPosition(float x, float y)
{
	position = Vector2f(x, y);

	body.setPosition(position);
	canon.setPosition(position);
	middle.setPosition(position);
}

sf::Vector2f Tank::getPosition() const
{
	return  position;
}

void Tank::update(const sf::Window& window)
{
	Vector2f a = static_cast<Vector2f>(Mouse::getPosition(window)) - canon.getPosition();

	canonAngle = atan2(a.y, a.x);
	canon.setRotation(canonAngle * 180 / M_PI);

	if (reload > 0.0)
		reload -= clock.restart().asSeconds(); //Zwraca czas jaki uplynal i resetuje zegar
}

double Tank::getCanonAngle() const
{
	return canonAngle;
}

/**
 * \brief Zwraca pozycje wylotu lufy czo³gu
 */
sf::Vector2f Tank::getMuzzlePosition() const
{
	return Vector2f{position + Vector2f(cos(canonAngle), sin(canonAngle))*canon.getSize().x };
}

sf::FloatRect Tank::getGlobalBounds() const
{
	return  FloatRect{ getPosition(), Vector2f(canon.getSize().x, canon.getSize().x)*2.0f };
}

const sf::Vector2f& Tank::getCanonSize() const
{
	return canon.getSize();
}

double Tank::getRadius() const
{
	return canon.getSize().x;
}

void Tank::fire(std::list<Projectile>& pociski)
{
	if (reload > 0.0) 
		return;

	Vector2f kierunek(std::cos(getCanonAngle()), std::sin(getCanonAngle())); //Wektor jednostkowy w kierunku lufy
	pociski.emplace_back(getMuzzlePosition(), getCanonSize().y / 5, kierunek * static_cast<float>(BULLET_SPEED));

	reload = RELOAD_TIME_IN_SECONDS;
	clock.restart();
}

double Tank::getReloadTime() const
{
	return reload>0 ? reload : 0.0;
}

double Tank::getMaxReloadTime() const
{
	return RELOAD_TIME_IN_SECONDS;
}

std::string Tank::getDebugInfo() const
{
	std::stringstream ss;
	ss << "Kat: " << std::setprecision(2) << std::fixed << getCanonAngle()*180.0/M_PI << "\t" << "Czas przeladowania: " << getReloadTime();

	return ss.str();
}

void Tank::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body, states);
	target.draw(canon, states);
	target.draw(middle, states);
}

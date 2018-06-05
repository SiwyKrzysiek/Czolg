#include "Target.h"

using namespace sf;

void Target::initialize()
{
	shape.setFillColor(randomColor());
	shape.setOutlineColor(randomColor());
	shape.setOutlineThickness(-2);
	shape.setOrigin(shape.getRadius(), shape.getRadius());

	number.setFillColor(Color::White);
	number.setOutlineColor(Color::Black);
	number.setOutlineThickness(2);
	number.setOrigin(number.getGlobalBounds().width / 2, number.getGlobalBounds().height / 1.3);
}

/**
 * \brief Konstruktor tworzacy cel wraz z numerem
 * \param font Czcionka do pola tekstowego
 * \param numer Numer wyswietlany w srodku
 */
Target::Target(const Font& font, int numer) : shape(rand() % 25 + 25),
number(std::to_string(numer), font, shape.getRadius()*1.5)
{
	initialize();
}

/**
 * \brief Konstruktor bez ustawiania liczby na celu
 * \param font Font czcionka do pola tekstowego
 */
Target::Target(const sf::Font& font) : shape(rand() % 25 + 25),
number("", font, shape.getRadius()*1.5)
{
	initialize();
}

void Target::setNumber(int numer)
{
	this->number.setString(std::to_string(numer));
}

void Target::update()
{
	shape.setPosition(getPosition());
	number.setPosition(getPosition());
}

sf::FloatRect Target::getGlobalBounds() const
{
	return FloatRect{ getPosition(), Vector2f(2.0*shape.getRadius(), 2.0*shape.getRadius()) };
}

double Target::getRadius()const
{
	return shape.getRadius();
}

sf::Vector2f Target::getPosition() const
{
	return Transformable::getPosition();
}

bool Target::intersects(const CircularShape& inny) const
{
	return intersect(*this, inny);
}

Vector2f Target::generatePosiblePlacment() const //ToDo Mozna zrobic lepiej
{
	double x = (SCREEN_WIDTH - GAMEPLAY_AREA_WIDTH) + randomDouble(shape.getRadius(), GAMEPLAY_AREA_WIDTH - shape.getRadius());
	double y = (SCREEN_HEIGHT - GAMEPLAY_AREA_HEIGHT) + randomDouble(shape.getRadius(), GAMEPLAY_AREA_HEIGHT - shape.getRadius());

	return Vector2f(x, y);
}

bool Target::operator==(const Target& cel) const
{
	return (
		cel.number.getString() == number.getString() &&
		cel.getPosition() == getPosition() &&
		cel.getRadius() == getRadius()
		);
}

void Target::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const_cast<Target*>(this)->update();

	target.draw(shape, states);
	target.draw(number, states);
}

#include "Cel.h"

using namespace sf;

void Cel::initialize()
{
	ksztalt.setFillColor(randomColor());
	ksztalt.setOutlineColor(randomColor());
	ksztalt.setOutlineThickness(-2);
	ksztalt.setOrigin(ksztalt.getRadius(), ksztalt.getRadius());

	numer.setFillColor(Color::White);
	numer.setOutlineColor(Color::Black);
	numer.setOutlineThickness(2);
	numer.setOrigin(numer.getGlobalBounds().width / 2, numer.getGlobalBounds().height / 1.3);
}

/**
 * \brief Konstruktor tworzacy cel wraz z numerem
 * \param font Czcionka do pola tekstowego
 * \param numer Numer wyswietlany w srodku
 */
Cel::Cel(const Font& font, int numer) : ksztalt(rand() % 25 + 25),
numer(std::to_string(numer), font, ksztalt.getRadius()*1.5)
{
	initialize();
}

/**
 * \brief Konstruktor bez ustawiania liczby na celu
 * \param font Font czcionka do pola tekstowego
 */
Cel::Cel(const sf::Font& font) : ksztalt(rand() % 25 + 25),
numer("", font, ksztalt.getRadius()*1.5)
{
	initialize();
}

void Cel::setNumber(int numer)
{
	this->numer.setString(std::to_string(numer));
}

void Cel::update()
{
	ksztalt.setPosition(getPosition());
	numer.setPosition(getPosition());
}

sf::FloatRect Cel::getGlobalBounds() const
{
	return FloatRect{ getPosition(), Vector2f(2.0*ksztalt.getRadius(), 2.0*ksztalt.getRadius()) };
}

double Cel::getRadius()const
{
	return ksztalt.getRadius();
}

sf::Vector2f Cel::getPosition() const
{
	return Transformable::getPosition();
}

bool Cel::intersects(const OkraglyKsztalt& inny) const
{
	return intersect(*this, inny);
}

Vector2f Cel::generatePosiblePlacment() const //ToDo Mozna zrobic lepiej
{

}

void Cel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const_cast<Cel*>(this)->update();

	target.draw(ksztalt, states);
	target.draw(numer, states);
}

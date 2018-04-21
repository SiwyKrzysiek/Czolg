#include "Cel.h"

using namespace sf;

Cel::Cel(const Font& font, int numer) : ksztalt(rand() % 25 + 25),
numer(std::to_string(numer), font, ksztalt.getRadius()*1.5)
{
	ksztalt.setFillColor(randomColor());
	ksztalt.setOutlineColor(randomColor());
	ksztalt.setOutlineThickness(-2);
	ksztalt.setOrigin(ksztalt.getRadius(), ksztalt.getRadius());

	Text& text = this->numer;
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height/1.3);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2);
}

void Cel::update()
{
	ksztalt.setPosition(getPosition());
	numer.setPosition(getPosition());
}

void Cel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const_cast<Cel*>(this)->update();

	//Font font;
	//font.loadFromFile("tahoma.ttf");
	//Text text("Test", font, 10);
	//text.setPosition(100, 100);
	//text.setFillColor(Color::Yellow);
	//
	//target.draw(text);

	target.draw(ksztalt, states);
	target.draw(numer, states);
}

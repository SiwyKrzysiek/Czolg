#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "CircularShape.h"
#include "Constants.h"

/**
 * \brief Zwraca losowt kolor nadajacy sie do pokolorowania Celu
 */
sf::Color randomColor();

template <typename A, typename B>
double rootSumSquared(A a, B b);

/**
 * \brief Ustawia origin prostokatnego obiektu w jego srodku
 * \tparam T typ majacy metody getGlobaBounds() i setOrigin()
 * \param object obiekt do ustawienia orgin 
 */
template <typename T>
void centerOriginInRectangle(T& object)
{
	object.setOrigin(static_cast<float>(object.getGlobalBounds().width) / 2.0f, static_cast<float>(object.getGlobalBounds().height) / 2.0f);
}

/**
 * \brief Liczy odleglosc miedzy dwoma punktammi
 * \param a puntk a 
 * \param b punkt b
 */
double distance(const sf::Vector2f& a, const sf::Vector2f& b);
double distance(const sf::Transformable& a, const sf::Transformable& b);
int random(int mini, int maxi);
double randomDouble(double mini, double maxi);
/**
 * \brief Zwraca losowy punkt nadajacy sie na postawienie celu
 * \return 
 */
sf::Vector2i randomPointInGamplayArea();
/**
 * \brief Sprawdza czy dwa OkragleKsztalty na siebie nachodza
 */
bool intersect(const CircularShape& a, const CircularShape& b);
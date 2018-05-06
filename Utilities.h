#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "OkraglyKsztalt.h"
#include "Stale.h"

/**
 * \brief Zwraca losowt kolor nadajacy sie do pokolorowania Celu
 */
sf::Color randomColor();

template <typename A, typename B>
double rootSumSquared(A a, B b);

/**
 * \brief Liczy odleglosc miedzy dwoma punktammi
 * \param a puntk a 
 * \param b punkt b
 */
double distance(const sf::Vector2f& a, const sf::Vector2f& b);
double distance(const sf::Transformable& a, const sf::Transformable& b);
int Losowa(int mini, int maxi);
double losowyDouble(double mini, double maxi);
/**
 * \brief Zwraca losowy punkt nadajacy sie na postawienie celu
 * \return 
 */
sf::Vector2i randomPointInGamplayArea();
/**
 * \brief Sprawdza czy dwa OkragleKsztalty na siebie nachodza
 */
bool intersect(const OkraglyKsztalt& a, const OkraglyKsztalt& b);
#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "OkraglyKsztalt.h"
#include "Stale.h"

sf::Color randomColor();
double rootSumSquared(int a, int b);
double rootSumSquared(double a, double b);
double distance(const sf::Vector2f& a, const sf::Vector2f& b);
double distance(const sf::Transformable& a, const sf::Transformable& b);
int Losowa(int mini, int maxi);
sf::Vector2i randomPointInGamplayArea();
bool intersect(const OkraglyKsztalt& a, const OkraglyKsztalt& b);
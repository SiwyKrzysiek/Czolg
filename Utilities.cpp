#include "Utilities.h"

using namespace sf;
using namespace std;

Color randomColor()
{
	return Color(rand() % 250 + 5, rand() % 250 + 5, rand() % 250 + 5);
}

template <typename A, typename B>
double rootSumSquared(A a, B b)
{
	return sqrt(static_cast<double>(a)*static_cast<double>(a) + static_cast<double>(b)*static_cast<double>(b));
}

double distance(const Vector2f& a, const Vector2f& b)
{
	return rootSumSquared(a.x - b.x, a.y - b.y);
}

double distance(const Transformable& a, const Transformable& b)
{
	return rootSumSquared(a.getPosition().x - b.getPosition().x, a.getPosition().y - b.getPosition().y);
}

Vector2i randomPointInGamplayArea()
{
	return Vector2i{ rand() % (SCREEN_WIDTH - 50), (rand() % (SCREEN_HEIGHT - 30)) + 30 };
}

 bool intersect(const CircularShape& a, const CircularShape& b)
{
	 double middlesDistance = distance(a.getPosition(), b.getPosition());
	 double raduisSum = a.getRadius() + b.getRadius();

	 return middlesDistance < raduisSum;
}

/**
 * \brief Zwraca losowa liczbe z przedzialu [mini, maxi)
 * \param mini 
 * \param maxi 
 * \return 
 */
int random(int mini, int maxi)
{
	return mini + rand() % (maxi - mini);
}

/**
 * \brief Zwraca losowa liczbe zmiennoprzcinkowa z przedzialu [mini, maxi]
 */
double randomDouble(double mini, double maxi)
{
	double f = static_cast<double>(rand()) / RAND_MAX;
	return mini + f * (maxi - mini);
}
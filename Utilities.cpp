#include "Utilities.h"



using namespace sf;
using namespace std;

Color randomColor()
{
	return Color(rand() % 250 + 5, rand() % 250 + 5, rand() % 250 + 5);
}

double rootSumSquared(int a, int b)
{
	return sqrt(a*a + b * b);
}

double rootSumSquared(double a, double b)
{
	return sqrt(a*a + b * b);
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

 bool intersect(const OkraglyKsztalt& a, const OkraglyKsztalt& b)
{
	 double odlegloscSrodkow = distance(a.getPosition(), b.getPosition());
	 double sumaPromieni = a.getRadius() + b.getRadius();

	 return odlegloscSrodkow < sumaPromieni;
}

/**
 * \brief Zwraca losowa liczbe z przedzialu [mini, maxi)
 * \param mini 
 * \param maxi 
 * \return 
 */
int Losowa(int mini, int maxi)
{
	return mini + rand() % (maxi - mini);
}

/**
 * \brief Zwraca losowa liczbe zmiennoprzcinkowa z przedzialu [mini, maxi]
 */
double losowyDouble(double mini, double maxi)
{
	double f = static_cast<double>(rand()) / RAND_MAX;
	return mini + f * (maxi - mini);
}
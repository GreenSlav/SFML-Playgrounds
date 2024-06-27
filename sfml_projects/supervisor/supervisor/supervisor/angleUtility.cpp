#include <SFML/Graphics.hpp>
#include "angleUtility.h"
#include "quarters.hpp"
#include <limits>

const double PI = 3.14159265358979323846;

Quarters getQuarter(sf::Vector2i& firstPoint, sf::Vector2i& secondPoint)
{
	if (firstPoint.x <= secondPoint.x && firstPoint.y >= secondPoint.y)
		return Quarters::First;
	if (firstPoint.x <= secondPoint.x && firstPoint.y <= secondPoint.y)
		return Quarters::Second;
	if (firstPoint.x >= secondPoint.x && firstPoint.y <= secondPoint.y)
		return Quarters::Third;
	if (firstPoint.x >= secondPoint.x && firstPoint.y >= secondPoint.y)
		return Quarters::Fourth;
}

float calculateAngle(Quarters quarter, sf::Vector2i& firstPoint, sf::Vector2i& secondPoint)
{
	float result = (int)quarter * 90 + (float)(std::atan((secondPoint.y - firstPoint.y) / (secondPoint.x - firstPoint.x == 0 ? std::numeric_limits<float>::epsilon() : secondPoint.x - firstPoint.x)) * 180 / PI);
	return result;
}
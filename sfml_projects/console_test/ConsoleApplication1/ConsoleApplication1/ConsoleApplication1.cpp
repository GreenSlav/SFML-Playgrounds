#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <limits>

enum class Quarters {
	First,
	Second,
	Third,
	Fourth,
};

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
	return (int)quarter * 90 + (float)(std::atan((secondPoint.y - firstPoint.y) / (secondPoint.x - firstPoint.x == 0 ? std::numeric_limits<float>::epsilon() : secondPoint.x - firstPoint.x)) * 180 / PI);
}

int main() {

	double TriangleRadius = 50.0f;
	int CenterX = 500 / 2.0f - TriangleRadius; // start of triangle 'square' x
	int CenterY = 500 / 2.0f - TriangleRadius; // start of triangle 'square' y

	float lengthOfTriangleSide = TriangleRadius * std::sqrt(3);
	float heightOfTriangle = lengthOfTriangleSide * std::sqrt(3) / 2.0f;
	float xShift = CenterX + lengthOfTriangleSide / 2.0f;
	float yShift = CenterY + heightOfTriangle - TriangleRadius;


	std::cout << CenterX << " " << CenterY << " " << xShift << " " << yShift;

	return 0;
}

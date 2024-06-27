#include <SFML/Graphics.hpp>
#include <string>
#include "quarters.hpp"
#include "angleUtility.h"

// Параметры окна
sf::VideoMode WindowResolution(1200, 700);
std::string Title = "Supervisor";

// Параметры треугольника
sf::Color TriangleColor = sf::Color::White;
double TriangleRadius = 50.0f;
float RotationAngle = 0.0f;
int startTriangleX = WindowResolution.width / 2.0f - TriangleRadius; // start of triangle 'square' x
int startTriangleY = WindowResolution.height / 2.0f - TriangleRadius; // start of triangle 'square' y
sf::Vector2i TrianglePos(startTriangleX, startTriangleY);

float lengthOfTriangleSide = TriangleRadius * std::sqrt(3);
float heightOfTriangle = lengthOfTriangleSide * std::sqrt(3) / 2.0f;
float xShift = startTriangleX + lengthOfTriangleSide / 2.0f;
float yShift = startTriangleY + heightOfTriangle - TriangleRadius;
sf::Vector2i trueTrianglePos(xShift, yShift);


// курсор мыши
sf::Vector2i сursorPos(0, 0);


int main()
{
	sf::RenderWindow window(WindowResolution, Title);

	while (window.isOpen())
	{
		//startingCursorPos = sf::Mouse::getPosition(window);

		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		// configuring triangle
		sf::Vector2f centerOfTrinagle(startTriangleX, startTriangleY);


		sf::CircleShape triangle(TriangleRadius, 3);
		triangle.setFillColor(TriangleColor);
		triangle.setPosition(centerOfTrinagle);

		// setting rotation
		сursorPos = sf::Mouse::getPosition(window);

		//Quarters variable = getQuarter(TrianglePos, сursorPos);
		float rotationAngle = calculateAngle(getQuarter(TrianglePos, сursorPos), TrianglePos, сursorPos); // почти пофиксил проблемы с углом
		triangle.setRotation(rotationAngle);
		// -----
		
		window.clear(sf::Color::Black);

		window.draw(triangle);

		window.display();
	}

	return 0;
}
#include <SFML/Graphics.hpp>
#include "vertexTriangleUtility.h"

sf::VertexArray generateVertexTriangle(sf::Vector2f centerOfTriangle, unsigned int radius)
{
	sf::VertexArray vertexArrayResult(sf::Triangles, 3);
	vertexArrayResult[0] = sf::Vector2f(centerOfTriangle.x - std::sqrt(3) * radius / 2.f, centerOfTriangle.y + radius / 2.f);
	vertexArrayResult[1] = sf::Vector2f(centerOfTriangle.x, centerOfTriangle.y - radius);
	vertexArrayResult[2] = sf::Vector2f(centerOfTriangle.x + std::sqrt(3) * radius / 2.f, centerOfTriangle.y + radius / 2.f);

	return vertexArrayResult;
}
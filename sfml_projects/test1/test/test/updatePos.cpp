#include <SFML/Graphics.hpp>

void updatePos(double a, double dt, sf::Vector2f* velocity, sf::Keyboard* KeyB) // a - speed, dt - delta time, velocity
{
	sf::Vector2f vec(0, 0);

	if (KeyB->isKeyPressed(sf::Keyboard::A))
	{
		vec.x -= a * dt;
	}
	if (KeyB->isKeyPressed(sf::Keyboard::D))
	{
		vec.x += a * dt;
	}
	if (KeyB->isKeyPressed(sf::Keyboard::W))
	{
		vec.y -= a * dt;
	}
	if (KeyB->isKeyPressed(sf::Keyboard::S))
	{
		vec.y += a * dt;
	}

	if (vec.x && vec.y)
	{
		velocity->x = vec.x * 0.7071;
		velocity->y = vec.y * 0.7071;
	}
	else
	{
		*velocity = vec;
	}
}

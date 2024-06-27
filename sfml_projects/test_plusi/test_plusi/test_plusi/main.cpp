#include <SFML/Graphics.hpp>	

sf::Keyboard KeyB;
double starting;
double ending;
double dt; // delta time

double speed = 300;
sf::Vector2f position;

sf::RectangleShape rect(sf::Vector2f(40, 40));

void updatePos(double a, double dt, sf::Vector2f* velocity) // a - speed, dt - delta time, velocity
{
	sf::Vector2f vec(0, 0);

	if (KeyB.isKeyPressed(sf::Keyboard::A))
	{
		vec.x -= a * dt;
	}
	if (KeyB.isKeyPressed(sf::Keyboard::D))
	{
		vec.x += a * dt;
	}
	if (KeyB.isKeyPressed(sf::Keyboard::W))
	{
		vec.y -= a * dt;
	}
	if (KeyB.isKeyPressed(sf::Keyboard::S))
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


int main()
{
	sf::Clock clock;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	
	sf::RenderWindow window(sf::VideoMode(600, 600), "Application", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		ending = clock.getElapsedTime().asSeconds();
		dt = ending - starting;
		starting = ending;
		

		sf::Event windowsEvent;
		while (window.pollEvent(windowsEvent))
		{
			if (windowsEvent.type == sf::Event::Closed)
				window.close();
		}

		rect.setFillColor(sf::Color::White);

		updatePos(speed, dt, &position);
		rect.move(position);

		window.clear(sf::Color::Black);

		window.draw(rect);

		window.display();
	}

	return 0;
}
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include "Collision.h"
#include "Rectangle.h"

int main()
{
	Collision collision;

	sf::RenderWindow window(sf::VideoMode(600, 600), "LJPhysichs", sf::Style::Default);
	window.setFramerateLimit(60);

	Rectangle rectankkeli(sf::Vector2f(100, 100), sf::Vector2f(40, 50), 50, 50);
	Rectangle rectankkeli2(sf::Vector2f(120, 0), sf::Vector2f(70, 50), 30, 20);
	rectankkeli.setFillColor(sf::Color::Green);
	rectankkeli2.setFillColor(sf::Color::Red);
	rectankkeli2.setVelocity(10);

	sf::Clock clock;
	float dt;
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		dt = clock.getElapsedTime().asSeconds();

		if (collision.collide(&rectankkeli, &rectankkeli2) && rectankkeli.getFillColor() != sf::Color::Blue)
		{
			rectankkeli.setFillColor(sf::Color::Blue);
			rectankkeli2.setFillColor(sf::Color::Blue);
		}
		else if (!collision.collide(&rectankkeli, &rectankkeli2) && rectankkeli.getFillColor() != sf::Color::Green)
		{
			rectankkeli.setFillColor(sf::Color::Green);
			rectankkeli2.setFillColor(sf::Color::Red);
		}

		if (rectankkeli.getPosition().y > window.getSize().y)
		{
			rectankkeli.setVelocity(rectankkeli.getVelocity() * -1);
			rectankkeli2.setVelocity(rectankkeli2.getVelocity() * -1);
		}

		rectankkeli.drop(dt);
		rectankkeli2.drop(dt);

		window.clear(sf::Color::White);
		window.draw(rectankkeli);
		window.draw(rectankkeli2);
		window.display();
	}
}
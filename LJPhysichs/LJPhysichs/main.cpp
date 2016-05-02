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
	Rectangle rectankkeli2(sf::Vector2f(90, 0), sf::Vector2f(70, 50), 30, 20);
	Rectangle rectankkeli3(sf::Vector2f(400, 400), sf::Vector2f(100, 100), 0, 20);
	rectankkeli.setFillColor(sf::Color::Green);
	rectankkeli2.setFillColor(sf::Color::Red);
	rectankkeli3.setFillColor(sf::Color::Magenta);
	rectankkeli2.setVelocity(sf::Vector2f(10, 10));

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

		rectankkeli.drop(dt);
		rectankkeli2.drop(dt);

		rectankkeli3.rotate(1);

		window.clear(sf::Color::White);
		window.draw(rectankkeli);
		window.draw(rectankkeli2);
		window.draw(rectankkeli3);
		window.display();
		//system("pause");
	}
}

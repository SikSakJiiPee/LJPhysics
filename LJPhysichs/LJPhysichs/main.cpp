#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include "Collision.h"
#include "Rectangle.h"
#include "World.h"

int main()
{
	World world;
	Collision collision;

	sf::RenderWindow window(sf::VideoMode(600, 600), "LJPhysichs", sf::Style::Default);
	window.setFramerateLimit(60);

	Rectangle rectankkeli(sf::Vector2f(100, 100), sf::Vector2f(40, 50), 50, 50);
	Rectangle rectankkeli2(sf::Vector2f(90, 0), sf::Vector2f(70, 50), 30, 20);
	Rectangle rectankkeli3(sf::Vector2f(400, 400), sf::Vector2f(100, 100), 0, 20);
	rectankkeli2.setVelocity(sf::Vector2f(10, 10));
	rectankkeli3.setStatic(true);

	rectankkeli.setFillColor(sf::Color::Green);
	rectankkeli2.setFillColor(sf::Color::Green);
	rectankkeli3.setFillColor(sf::Color::Green);

	world.objects.push_back(rectankkeli);
	world.objects.push_back(rectankkeli2);
	world.objects.push_back(rectankkeli3);

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

		world.update(dt);

		world.objects[2].rotate(1);

		window.clear(sf::Color::White);
		for (int i = 0; i < world.objects.size(); i++)
		{
			window.draw(world.objects[i]);
		}
		window.display();
		//system("pause");
	}
}

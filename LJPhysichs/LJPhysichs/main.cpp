#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include "Collision.h"
#include "Rectangle.h"
#include "World.h"

#include <random>
#include <math.h>

int main()
{
	srand(time(NULL));

	World world;
	Collision collision;

	sf::RenderWindow window(sf::VideoMode(1200, 900), "LJPhysichs", sf::Style::Default);
	window.setFramerateLimit(60);

	Rectangle rectankkeli;
	rectankkeli.setStatic(true);
	rectankkeli.setSize(sf::Vector2f(20, 20));
	rectankkeli.setFillColor(sf::Color::Black);
	rectankkeli.setMass(999999);
	rectankkeli.setElasticity(0.5);
	for (int i = 0; i < 25; i++)
	{
		rectankkeli.setPosition(sf::Vector2f(rand() % 1200, rand() % 900));
		world.objects.push_back(rectankkeli);
	}

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

			if (event.type == sf::Event::MouseButtonPressed)
			{
				unsigned randomMass = rand() % 200;
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				Rectangle uusRectankkeli(sf::Vector2f(mouse), sf::Vector2f(50, 50), 20, sf::Vector2f(0, 0), 0.5, randomMass, sf::Color::Green);
				uusRectankkeli.setOutlineThickness(1);
				uusRectankkeli.setOutlineColor(sf::Color::Black);
				world.objects.push_back(uusRectankkeli);
			}
		}

		dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		world.update(dt);

		window.clear(sf::Color::White);
		for (int i = 0; i < world.objects.size(); i++)
		{
			window.draw(world.objects[i]);
			if (world.objects[i].getPosition().y > 1000)
			{
				std::cout << "Deleted object " << i << std::endl;
				world.objects.erase(world.objects.begin() + i);
				i--;
			}
		}
		window.display();


		//system("pause");
	}
}

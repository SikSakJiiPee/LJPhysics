#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include "Collision.h"

int main()
{
	Collision collision;

	sf::RenderWindow window(sf::VideoMode(600, 600), "LJPhysichs", sf::Style::Default);

	sf::RectangleShape rectankkeli(sf::Vector2f(20, 20));
	rectankkeli.setFillColor(sf::Color::Green);
	rectankkeli.setPosition(sf::Vector2f(50, 100));
	rectankkeli.setRotation(50);

	sf::RectangleShape rectankkeli2(sf::Vector2f(20, 20));
	rectankkeli2.setFillColor(sf::Color::Red);
	rectankkeli2.setPosition(sf::Vector2f(62, 0));
	rectankkeli2.setRotation(30);

	while (window.isOpen())
	{
		if (collision.collide(&rectankkeli, &rectankkeli2))
		{
			std::cout << "Jee!";
		}


		rectankkeli.move(sf::Vector2f(0, 0.0));
		rectankkeli2.move(sf::Vector2f(0, 0.01));

		window.clear(sf::Color::White);
		window.draw(rectankkeli);
		window.draw(rectankkeli2);
		window.display();
	}
}

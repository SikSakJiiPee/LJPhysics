#pragma once

#include <SFML/Graphics.hpp>
#include "Physics.h"

class Rectangle : public sf::RectangleShape, public Physics
{
public:
	Rectangle();
	Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, sf::Vector2f vel, float e, float m´, sf::Color c);
	~Rectangle();
};


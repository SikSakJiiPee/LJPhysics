#include "Rectangle.h"


Rectangle::Rectangle() : sf::RectangleShape(), Physics()
{
}

Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, sf::Vector2f vel, float e, float m, sf::Color c) : sf::RectangleShape(), Physics()
{
	setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	setPosition(pos);
	setSize(size);
	setRotation(angle);
	setFillColor(c);
	setVelocity(vel);
	setElasticity(e);
	setMass(m);
}

Rectangle::~Rectangle()
{
}
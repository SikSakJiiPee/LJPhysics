#include "Rectangle.h"


Rectangle::Rectangle() : sf::RectangleShape()
{
}

Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, float m) : sf::RectangleShape()
{
	setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	setPosition(pos);
	setSize(size);
	setRotation(angle);
	mass = m;
}

Rectangle::~Rectangle()
{
}

void Rectangle::drop(float dt)
{
	velocity.y = velocity.y - gravity * dt;
	setPosition(getPosition().x, getPosition().y + velocity.y * dt);
}

void Rectangle::setMass(float m)
{
	mass = m;
}

float Rectangle::getMass()
{
	return mass;
}

void Rectangle::setVelocity(sf::Vector2f v)
{
	velocity = v;
}

sf::Vector2f Rectangle::getVelocity()
{
	return velocity;
}

void Rectangle::setElasticity(float e)
{
	elasticity = e;
	if (elasticity > 1)
	{
		elasticity = 1.0;
	}
	else if (elasticity < 0)
	{
		elasticity = 0.0;
	}
}

float Rectangle::getElasticity()
{
	return elasticity;
}
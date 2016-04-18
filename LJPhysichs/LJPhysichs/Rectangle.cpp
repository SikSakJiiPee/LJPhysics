#include "Rectangle.h"


Rectangle::Rectangle() : sf::RectangleShape()
{
}

Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, float m) : sf::RectangleShape()
{
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
	velocity = velocity - gravity * dt;
	setPosition(getPosition().x, getPosition().y + velocity * dt);
}

void Rectangle::setMass(float m)
{
	mass = m;
}

float Rectangle::getMass()
{
	return mass;
}

void Rectangle::setVelocity(float v)
{
	velocity = v;
}

float Rectangle::getVelocity()
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
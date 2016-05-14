#include "Physics.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

void Physics::setMass(float m)
{
	mass = m;
}

float Physics::getMass()
{
	return mass;
}

void Physics::setVelocity(sf::Vector2f v)
{
	velocity = v;
}

sf::Vector2f Physics::getVelocity()
{
	return velocity;
}

void Physics::setAngularVelocity(sf::Vector2f v)
{
	angularVelocity = v;
}

sf::Vector2f Physics::getAngularVelocity()
{
	return angularVelocity;
}

void Physics::setElasticity(float e)
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

float Physics::getElasticity()
{
	return elasticity;
}

bool Physics::getStatic()
{
	return staticRectangle;
}

void Physics::setStatic(bool s)
{
	staticRectangle = s;
}
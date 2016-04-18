#pragma once

#include <SFML/Graphics.hpp>

#include "Physics.h"

class Rectangle : public sf::RectangleShape, Physics
{
public:
	Rectangle();
	Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, float m);
	~Rectangle();

	void drop(float dt);

	void setMass(float m);
	float getMass();
	void setVelocity(float v);
	float getVelocity();
	void setElasticity(float e);
	float getElasticity();


private:
	float mass = 10;
	float elasticity = 0;
	float velocity = 0;

};


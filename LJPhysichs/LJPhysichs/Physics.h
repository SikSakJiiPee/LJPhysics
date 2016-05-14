#pragma once

#include <SFML/Graphics.hpp>

class Physics
{
public:
	Physics();
	~Physics();

	void setMass(float m);
	float getMass();
	void setVelocity(sf::Vector2f v);
	sf::Vector2f getVelocity();
	void setAngularVelocity(sf::Vector2f v);
	sf::Vector2f getAngularVelocity();
	void setElasticity(float e);
	float getElasticity();
	bool getStatic();
	void setStatic(bool s);


	bool staticRectangle = false;
	float mass = 10;
	float elasticity = 0;
	sf::Vector2f velocity = { 0, 0 };
	sf::Vector2f angularVelocity = { 0, 0 };	
};


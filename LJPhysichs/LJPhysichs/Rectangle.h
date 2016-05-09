#pragma once

#include <SFML/Graphics.hpp>

class Rectangle : public sf::RectangleShape
{
public:
	Rectangle();
	Rectangle(sf::Vector2f pos, sf::Vector2f size, float angle, float m);
	~Rectangle();

	void setMass(float m);
	float getMass();
	void setVelocity(sf::Vector2f v);
	sf::Vector2f getVelocity();
	void setElasticity(float e);
	float getElasticity();
	bool getStatic();
	void setStatic(bool s);

private:
	bool staticRectangle = false;
	float mass = 10;
	float elasticity = 0;
	sf::Vector2f velocity = { 0, 0 };

};


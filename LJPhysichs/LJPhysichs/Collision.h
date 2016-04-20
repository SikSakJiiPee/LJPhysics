#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include <iostream>

struct rectangle
{
	sf::Vector2f vertex[4];
};

class Collision
{
public:
	Collision();
	~Collision();

	bool collide(const sf::RectangleShape* rect, const sf::RectangleShape* rect2);

private:
	void project(sf::Vector2f& axis, rectangle* _rectangle, float &min, float &max);
	void normalize(sf::Vector2f& vector);
	float dot(sf::Vector2f& vector1, sf::Vector2f& vector2);
	float distance(float minA, float maxA, float minB, float maxB);
};


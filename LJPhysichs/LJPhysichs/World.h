#pragma once

#include "Rectangle.h"
#include "Collision.h"
#include "Physics.h"

#include <vector>
#include <algorithm>
#include <math.h>

class World
{
public:
	World();
	~World();

	void update(float dt);

	sf::Vector2f getGravity();
	void setGravity(const sf::Vector2f g);
	void collisionEffects(unsigned i, unsigned j);
	void rotation(unsigned i, float dt);

	std::vector<Rectangle>objects;

private:
	void collisionChecks(float dt);

	Collision collision;
	sf::Vector2f gravity = { 0, 98.0665 };
};


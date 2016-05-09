#pragma once

#include "Rectangle.h"
#include "Collision.h"

#include <vector>

class World
{
public:
	World();
	~World();

	void update(float dt);

	float getGravity();
	void setGravity(const float g);

	std::vector<Rectangle>objects;

private:
	void collisionChecks(float dt);

	Collision collision;
	float gravity = 9.80665;
};


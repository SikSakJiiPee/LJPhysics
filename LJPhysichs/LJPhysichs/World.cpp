#include "World.h"


World::World()
{
}


World::~World()
{
}

void World::update(float dt)
{
	collisionChecks(dt);

	for (int i = 0; i < objects.size(); i++)
	{
		if (!objects[i].getStatic())
		{
			objects[i].setVelocity(sf::Vector2f(0, objects[i].getVelocity().y + gravity * dt));
			objects[i].setPosition(objects[i].getPosition().x, objects[i].getPosition().y + objects[i].getVelocity().y * dt);
		}
	}
}

void World::collisionChecks(float dt)
{
	float elasticity;
	sf::Vector2f r1, r2, n, testi, vab, impulseA, impulseB;
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = 0; j < objects.size(); j++)
		{
			if (i != j && collision.collide(&objects[i], &objects[j]))
			{
				std::cout << "Collision between objects " << i << " & " << j << std::endl;
				r1 = collision.getCollisionVector(&objects[i], &objects[j]);
				r2 = collision.getCollisionVector(&objects[j], &objects[i]);

				if (objects[i].getElasticity() < objects[j].getElasticity())
				{
					elasticity = objects[i].getElasticity();
				}
				else
				{
					elasticity = objects[j].getElasticity();
				}

				vab = objects[i].getVelocity() - objects[j].getVelocity();

				//testi = (-(1 + elasticity)*vab*n) / ((n*n*(i / objects[i].getMass() + 1 / objects[j].getMass()) + ((r1*n)^2)/impulseA + ((r2*n)^2)/impulseB));
			}
		}
	}
}

float World::getGravity()
{
	return gravity;
}

void World::setGravity(const float g)
{
	gravity = g;
}
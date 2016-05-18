#include "World.h"


World::World()
{
}


World::~World()
{
}

void World::update(float dt)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (!objects[i].getStatic())
		{
			rotation(i, dt);

			objects[i].setVelocity(sf::Vector2f(objects[i].getVelocity().x + gravity.x * dt, objects[i].getVelocity().y + gravity.y * dt));
			objects[i].setPosition(objects[i].getPosition().x + objects[i].getVelocity().x * dt, objects[i].getPosition().y + objects[i].getVelocity().y * dt);
		}
	}
	collisionChecks();
}

void World::collisionChecks()
{
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			if (collision.collide(&objects[i], &objects[j]))
			{
				collisionEffects(i, j);
			}
		}
	}
}

sf::Vector2f World::getGravity()
{
	return gravity;
}

void World::setGravity(const sf::Vector2f g)
{
	gravity = g;
}

void World::collisionEffects(unsigned i, unsigned j)
{
	float angle = collision.getCollisionAngle(&objects[i], &objects[j]), elasticity, mass1 = objects[i].getMass(), mass2 = objects[j].getMass();
<<<<<<< HEAD

=======
>>>>>>> origin/master
	sf::Vector2f v1bxy = objects[i].getVelocity(), v2bxy = objects[j].getVelocity(), v1axy, v2axy, v1bnt, v2bnt, v1ant, v2ant;

	if (objects[i].getElasticity() < objects[j].getElasticity())
	{
		elasticity = objects[i].getElasticity();
	}
	else
	{
		elasticity = objects[j].getElasticity();
	}

	v1bnt = sf::Vector2f(v1bxy.x * cos(angle) + v1bxy.y * sin(angle), v1bxy.x * -sin(angle) + v1bxy.y * cos(angle));
	v2bnt = sf::Vector2f(v2bxy.x * cos(angle) + v2bxy.y * sin(angle), v2bxy.x * -sin(angle) + v2bxy.y * cos(angle));

	v1ant = sf::Vector2f((mass1- elasticity * mass2)/(mass1 + mass2) * v1bnt.x + ((1+elasticity)*mass2)/(mass1 + mass2) * v2bnt.x, v1bnt.y);
	v2ant = sf::Vector2f(((1 + elasticity)*mass1) / (mass1 + mass2) * v1bnt.x + (mass2 - elasticity * mass1) / (mass1 + mass2) * v2bnt.x, v2bnt.y);

	v1axy = sf::Vector2f(v1ant.x * cos(angle) + v1ant.y * -sin(angle), v1ant.x * sin(angle) + v1ant.y * cos(angle));
	v2axy = sf::Vector2f(v2ant.x * cos(angle) + v2ant.y * -sin(angle), v2ant.x * sin(angle) + v2ant.y * cos(angle));

<<<<<<< HEAD
	if (!objects[i].getStatic() && !objects[j].getStatic())
	{
		v1axy.x *= -1;
		v2axy.x *= -1;
	}

=======
>>>>>>> origin/master
	if (!objects[i].getStatic())
	{
		objects[i].setVelocity(v1axy);
	}
	if (!objects[j].getStatic())
	{
		objects[j].setVelocity(v2axy);
	}
}

void World::rotation(unsigned i, float dt)
{
<<<<<<< HEAD
	//objects[i].rotate();
}












































/*
float dav = 0, angle = 0, direction = 1;

if (objects[i].getVelocity().y == 0)
{
	return;
}

angle = atan(objects[i].getVelocity().x / objects[i].getVelocity().y);
dav = sqrt(objects[i].getVelocity().x * objects[i].getVelocity().x + objects[i].getVelocity().y * objects[i].getVelocity().y) * sin(angle) / objects[i].getSize().x;
objects[i].setAngularVelocity(sf::Vector2f(objects[i].getAngularVelocity().x + dav * dt, objects[i].getAngularVelocity().y + dav * dt));
if (objects[i].getVelocity().x < 0)
{
	direction = -1;
}
objects[i].rotate(direction * sqrt(objects[i].getAngularVelocity().x  * objects[i].getAngularVelocity().x + objects[i].getAngularVelocity().y * objects[i].getAngularVelocity().y));
*/
=======
	float dav = 0, angle = 0, direction = 1;
	if (objects[i].getVelocity().y > 0)
	{
		angle = atan(objects[i].getVelocity().x / objects[i].getVelocity().y);
		dav = sqrt(objects[i].getVelocity().x * objects[i].getVelocity().x + objects[i].getVelocity().y + objects[i].getVelocity().y) * angle / objects[i].getSize().x;
	}
	if (angle >= 0)
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}

	objects[i].setAngularVelocity(sf::Vector2f(objects[i].getAngularVelocity().x + dav * dt, objects[i].getAngularVelocity().y + dav * dt));
	objects[i].rotate(direction * sqrt(objects[i].getAngularVelocity().x  * objects[i].getAngularVelocity().x + objects[i].getAngularVelocity().y * objects[i].getAngularVelocity().y));

}
>>>>>>> origin/master

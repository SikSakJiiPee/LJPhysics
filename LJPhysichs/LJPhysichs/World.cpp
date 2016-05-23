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
			objects[i].rotate(objects[i].dav);
			objects[i].setVelocity(sf::Vector2f(objects[i].getVelocity().x + gravity.x * dt, objects[i].getVelocity().y + gravity.y * dt));
			objects[i].setPosition(objects[i].getPosition().x + objects[i].getVelocity().x * dt, objects[i].getPosition().y + objects[i].getVelocity().y * dt);
		}
	}
	collisionChecks(dt);
}

void World::collisionChecks(float dt)
{
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			if (collision.collide(&objects[i], &objects[j]))
			{
				float angle = collision.getCollisionAngle(&objects[i], &objects[j]), elasticity, mass1 = objects[i].getMass(), mass2 = objects[j].getMass();
				sf::Vector2f v1bxy = objects[i].getVelocity(), v2bxy = objects[j].getVelocity(), v1axy, v2axy, v1bnt, v2bnt, v1ant, v2ant, nollavektori;
				nollavektori = sf::Vector2f(0.0, 0.0);

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

				v1ant = sf::Vector2f((mass1 - elasticity * mass2) / (mass1 + mass2) * v1bnt.x + ((1 + elasticity)*mass2) / (mass1 + mass2) * v2bnt.x, v1bnt.y);
				v2ant = sf::Vector2f(((1 + elasticity)*mass1) / (mass1 + mass2) * v1bnt.x + (mass2 - elasticity * mass1) / (mass1 + mass2) * v2bnt.x, v2bnt.y);

				v1axy = sf::Vector2f(v1ant.x * cos(angle) + v1ant.y * -sin(angle), v1ant.x * sin(angle) + v1ant.y * cos(angle));
				v2axy = sf::Vector2f(v2ant.x * cos(angle) + v2ant.y * -sin(angle), v2ant.x * sin(angle) + v2ant.y * cos(angle));

				//if (v1bnt.x - v2bnt.x < nollavektori.x)
				//if (v1ant.x - v2ant.x < nollavektori.x)
				//if (v1axy.x - v2axy.x < nollavektori.x)
				//if (v1bnt.x - v2bnt.x < nollavektori.x || v1axy.x - v2axy.x < nollavektori.x || v1bnt.y - v2bnt.y < nollavektori.y || v1axy.y - v2axy.y < nollavektori.y)
				if (v1bnt.x - v2bnt.x < nollavektori.x || v1axy.x - v2axy.x < nollavektori.x)
				
				//if (v1bnt.y - v2bnt.y < nollavektori.y)
				//if (v1ant.y - v2ant.y < nollavektori.y)
				//if (v1axy.y - v2axy.y < nollavektori.y)
				//if (v1ant.y - v2ant.y < nollavektori.y || v1axy.y - v2axy.y < nollavektori.y)
				{
					collisionEffects(i, j);
					rotation(i, dt);
					rotation(j, dt);
				}
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

	if (!objects[i].getStatic() && !objects[j].getStatic())
	{
		v1axy.x *= -1;
		v2axy.x *= -1;
	}

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
	float angle = 0;

	if (objects[i].getVelocity().y == 0)
	{
		return;
	}

	angle = atan(objects[i].getVelocity().x / objects[i].getVelocity().y);
	objects[i].dav = sqrt(objects[i].getVelocity().x * objects[i].getVelocity().x + objects[i].getVelocity().y * objects[i].getVelocity().y) * sin(angle) / objects[i].getSize().x;

}
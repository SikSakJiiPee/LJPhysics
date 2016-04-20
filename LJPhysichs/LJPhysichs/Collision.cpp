#include "Collision.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::collide(const sf::RectangleShape* rect, const sf::RectangleShape* rect2)
{
	rectangle one;
	rectangle two;

	sf::Transform transform = rect->getTransform();
	sf::FloatRect floatRect = rect->getLocalBounds();

	one.vertex[0] = transform.transformPoint(sf::Vector2f(floatRect.left, floatRect.top));
	one.vertex[1] = transform.transformPoint(sf::Vector2f(floatRect.left + floatRect.width, floatRect.top));
	one.vertex[2] = transform.transformPoint(sf::Vector2f(floatRect.left + floatRect.width, floatRect.top + floatRect.height));
	one.vertex[3] = transform.transformPoint(sf::Vector2f(floatRect.left, floatRect.top + floatRect.height));

	transform = rect2->getTransform();
	floatRect = rect2->getLocalBounds();

	two.vertex[0] = transform.transformPoint(sf::Vector2f(floatRect.left, floatRect.top));
	two.vertex[1] = transform.transformPoint(sf::Vector2f(floatRect.left + floatRect.width, floatRect.top));
	two.vertex[2] = transform.transformPoint(sf::Vector2f(floatRect.left + floatRect.width, floatRect.top + floatRect.height));
	two.vertex[3] = transform.transformPoint(sf::Vector2f(floatRect.left, floatRect.top + floatRect.height));

	sf::Vector2f axis;
	float minA;
	float minB;
	float maxA;
	float maxB;

	axis.x = one.vertex[1].x - one.vertex[0].x;
	axis.y = one.vertex[1].y - one.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB) > 0.f)
	{
		return false;
	}

	axis.x = one.vertex[3].x - one.vertex[0].x;
	axis.y = one.vertex[3].y - one.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB) > 0.f)
	{
		return false;
	}

	axis.x = two.vertex[1].x - two.vertex[0].x;
	axis.y = two.vertex[1].y - two.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB) > 0.f)
	{
		return false;
	}

	axis.x = two.vertex[3].x - two.vertex[0].x;
	axis.y = two.vertex[3].y - two.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB) > 0.f)
	{
		return false;
	}
	else
	{
		return true;
	}

}


void Collision::normalize(sf::Vector2f& vector) {
	const float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length == 0)
	{
		return;
	}
	vector.x = vector.x / length;
	vector.y = vector.y / length;
}

float Collision::dot(sf::Vector2f& vector1, sf::Vector2f& vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}

float Collision::distance(float minA, float maxA, float minB, float maxB)
{
	if (minB > maxA)
	{
		return minB - maxA;
	}
	return minA - maxB;
}

void  Collision::project(sf::Vector2f& axis, rectangle* _rectangle, float &min, float &max)
{
	float myDot = dot(axis, _rectangle->vertex[0]);

	min = myDot;
	max = myDot;

	for (short i = 1; i<4; i++)
	{
		myDot = dot(_rectangle->vertex[i], axis);

		if (myDot < min)
		{
			min = myDot;
		}
		else if (myDot > max)
		{
			max = myDot;
		}
	}
}
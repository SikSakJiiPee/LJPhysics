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

sf::Vector2f Collision::getCollisionVector(const sf::RectangleShape* rect, const sf::RectangleShape* rect2)
{
	sf::Vector2f radius = { 0, 0 };

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

	sf::Vector2f tempVecMin1 = one.vertex[0], tempVecMax1 = one.vertex[0];
	sf::Vector2f tempVecMin2 = two.vertex[0], tempVecMax2 = two.vertex[0];

	for (int i = 0; i < 4; i++)
	{
		if (one.vertex[i].x > tempVecMax1.x){ tempVecMax1.x = one.vertex[i].x; }
		if (one.vertex[i].x < tempVecMin1.x){ tempVecMin1.x = one.vertex[i].x; }
		if (one.vertex[i].y > tempVecMax1.y){ tempVecMax1.y = one.vertex[i].y; }
		if (one.vertex[i].y < tempVecMin1.y){ tempVecMin1.y = one.vertex[i].y; }
		if (two.vertex[i].x > tempVecMax2.x){ tempVecMax2.x = two.vertex[i].x; }
		if (two.vertex[i].x < tempVecMin2.x){ tempVecMin2.x = two.vertex[i].x; }
		if (two.vertex[i].y > tempVecMax2.y){ tempVecMax2.y = two.vertex[i].y; }
		if (two.vertex[i].y < tempVecMin2.y){ tempVecMin2.y = two.vertex[i].y; }
	}

	for (int i = 0; i < 4; i++)
	{
		if (tempVecMin1.x < two.vertex[i].x && tempVecMax1.x > two.vertex[i].x && tempVecMin1.y < two.vertex[i].y && tempVecMax1.y > two.vertex[i].y)
		{
			radius = { two.vertex[i].x - tempVecMin2.x - ((tempVecMax2.x - tempVecMin2.x) / 2), two.vertex[i].y - tempVecMin2.y - ((tempVecMax2.y - tempVecMin2.y) / 2) };
		}
	}

	return radius;
}

/*
std::cout << two.vertex[i].x << "," << two.vertex[i].y << std::endl;
// Laskuvirhe pankissa sinun eduksesi, sait 200 markkaa
sf::Vector2f distanceToCenter = { abs(abs(rect2->getOrigin().x) - abs(two.vertex[i].x)), abs(abs(rect2->getOrigin().y) - abs(two.vertex[i].y)) };
std::cout << distanceToCenter.x << "," << distanceToCenter.y << std::endl;
*/


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
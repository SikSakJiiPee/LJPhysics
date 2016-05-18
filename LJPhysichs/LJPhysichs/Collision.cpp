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
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
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

float Collision::getCollisionAngle(const sf::RectangleShape* rect, const sf::RectangleShape* rect2)
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

	sf::Vector2f point1, point2;
	point1 = sf::Vector2f(tempVecMin1.x + (tempVecMax1.x - tempVecMin1.x) / 2, tempVecMin1.y + (tempVecMax1.y - tempVecMin1.y) / 2);
	point2 = sf::Vector2f(tempVecMin2.x + (tempVecMax2.x - tempVecMin2.x) / 2, tempVecMin2.y + (tempVecMax2.y - tempVecMin2.y) / 2);

	sf::Vector2f catheti = sf::Vector2f((point1.x - point2.x), (point1.y - point2.y));
<<<<<<< HEAD

	float angle = abs(atan(catheti.x / catheti.y));

	if (point1.x <= point2.x && point1.y >= point2.y) // Up-right corner 
	{
		angle = -(90 * 3.14 / 180 - angle);
	}
	if (point1.x >= point2.x && point1.y >= point2.y) // Up-left corner 
	{
		angle = (90 * 3.14 / 180 - angle);
	}
	if (point1.x >= point2.x && point1.y <= point2.y) // Down-left corner
	{
		angle = (90 * 3.14 / 180 - angle);
	}
	if (point1.x <= point2.x && point1.y <= point2.y) // Down-right corner 
	{
		angle = -(90 * 3.14 / 180 - angle);
	}

	std::cout << angle * 180 / 3.14 << std::endl;


	return angle;
=======

	float angle = atan(catheti.x / catheti.y);
	return angle;

	//float angledegree = angle * 180 / 3.14;
	//std::cout << angledegree << std::endl;
>>>>>>> origin/master
}


/*
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
*/
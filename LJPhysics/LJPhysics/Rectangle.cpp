#include "Rectangle.h"

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(unsigned w, unsigned h)
{
	width = w;
	height = h;
}


Rectangle::~Rectangle()
{
}

void Rectangle::setSize(unsigned w, unsigned h)
{
	width = w;
	height = h;
}

unsigned Rectangle::getWidth()
{
	return width;
}

unsigned Rectangle::getHeight()
{
	return height;
}
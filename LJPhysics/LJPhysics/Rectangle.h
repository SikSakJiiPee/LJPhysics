#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(unsigned w, unsigned h);
	~Rectangle();

	void setSize(unsigned w, unsigned h);
	unsigned getWidth(), getHeight();

	unsigned width;
	unsigned height;
};


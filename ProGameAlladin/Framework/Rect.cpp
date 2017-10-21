#include "Rect.h"

Rect::Rect()
{
}

Rect::~Rect()
{
	
}

float Rect::getX() const
{
	return _x;
}

void Rect::setX(const float& x)
{
	_x = x;
}

float Rect::getY() const
{
	return _y;
}

void Rect::setY(const float& y)
{
	_y = y;
}

float Rect::getWidth() const
{
	return _width;
}

void Rect::setWidth(const float& width)
{
	_width = width;
}

float Rect::getHeight() const
{
	return _height;
}

void Rect::setHeight(const float& height)
{
	_height = height;
}





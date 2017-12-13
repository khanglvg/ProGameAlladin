#include "Rect.h"

US_NS_JK
Rect::Rect()
{
	_x = 0.0f;
	_y = 0.0f;
	_width = 0.0f;
	_height = 0.0f;
}

Rect::~Rect()
{
	
}

Rect::Rect(const float& x, const float& y, const float& width, const float& height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
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

float Rect::getMinX() const
{
	return _x;
}

float Rect::getMidX() const
{
	return _x + _width / 2.0f;
}

float Rect::getMaxX() const
{
	return _x + _width;
}

float Rect::getMinY() const
{
	return _y;
}

float Rect::getMidY() const
{
	return _y + _height / 2.0f;
}

float Rect::getMaxY() const
{
	return _y + _height;
}

bool Rect::equals(const Rect& rect) const
{
	if (_width == rect._width && _height == rect._height)
		return true;
	else
		return false;
}

bool Rect::containsPoint(const Vec2& point) const
{
	if (point.x >= getMinX() && point.x <= getMaxX()
		&& point.y >= getMinY() && point.y <= getMaxY())
	{
		return true;
	}

	else
		return false;
}




const Rect Rect::ZERO = Rect(0, 0, 0, 0);




#include "Size.h"
US_NS_JK

Size::Size():_width(0.0f), _height(0.0f)
{
}

Size::Size(const float& width, const float& height)
{
	_width = width;
	_height = height;
}

Size::~Size()
{
}

float Size::getWidth() const
{
	return _width;
}

void Size::setWidth(const float& width)
{
	_width = width;
}

float Size::getHeight() const
{
	return _height;
}

void Size::setHeight(const float& height)
{
	_height = height;
}

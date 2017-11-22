#include "Size.h"

JaKa::Size::Size():_width(0.0f), _height(0.0f)
{
}

JaKa::Size::~Size()
{
}

float JaKa::Size::getWidth() const
{
	return _width;
}

void JaKa::Size::setWidth(const float& width)
{
	_width = width;
}

float JaKa::Size::getHeight() const
{
	return _height;
}

void JaKa::Size::setHeight(const float& height)
{
	_height = height;
}

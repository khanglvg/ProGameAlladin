#include "Color.h"


Color::Color()
{
}

Color::Color(const char& red, const char& green, const char& blue, const char& alpha)
{
	_red = red;
	_green = green;
	_blue = blue;
	_alpha = alpha;
}

Color::~Color()
{
}

#pragma region GET-SET
char Color::getRed()
{
	return _red;
}

void Color::setRed(const char& red)
{
	_red = red;
}

char Color::getGreen()
{
	return _green;
}

void Color::setGreen(const char& green)
{
	_green = green;
}

char Color::getBlue()
{
	return _blue;
}

void Color::setBlue(const char& blue)
{
	_blue = blue;
}

char Color::getAlpha()
{
	return _alpha;
}

void Color::setAlpha(const char& alpha)
{
	_alpha = alpha;
}
#pragma  endregion 
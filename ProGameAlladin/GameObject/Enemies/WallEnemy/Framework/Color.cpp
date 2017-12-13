#include "Color.h"

US_NS_JK

Color::Color()
{
	_red = 0;
	_blue = 0;
	_green = 0;
	_alpha = 0;
}

Color::Color(const unsigned char& red, 
			 const unsigned char& green, 
			 const unsigned char& blue, 
			 const unsigned char& alpha)
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
unsigned char Color::getRed() const
{
	return _red;
}

void Color::setRed(const unsigned char& red)
{
	_red = red;
}

unsigned char Color::getGreen() const
{
	return _green;
}

void Color::setGreen(const unsigned char& green)
{
	_green = green;
}

unsigned char Color::getBlue() const
{
	return _blue;
}

void Color::setBlue(const unsigned char& blue)
{
	_blue = blue;
}

unsigned char Color::getAlpha() const
{
	return _alpha;
}

void Color::setAlpha(const unsigned char& alpha)
{
	_alpha = alpha;
}
#pragma endregion 



bool Color::operator==(const Color& color) const
{
	if (_red == color._red &&
		_green == color._green &&
		_blue == color._blue &&
		_alpha == color._alpha)
		return true;
	else
		return false;
}




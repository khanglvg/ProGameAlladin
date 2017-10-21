#ifndef __RECT_H__

#define __RECT_H__


#include "definitions.h"
class Rect
{
public:
	Rect();
	~Rect();

#pragma region GET-SET
	float getX() const;
	void setX(const float& x);
	float getY() const;
	void setY(const float& y);
	float getWidth() const;
	void setWidth(const float& width);
	float getHeight() const;
	void setHeight(const float& height);
#pragma endregion 



private:
	// Delare coordinate top-left
	float _x, _y;

	// Delare width-height
	float _width, _height;

};


#endif // __RECT_H__
#ifndef __RECT_H__

#define __RECT_H__


#include "definitions.h"
#include "Vec2.h"
NS_JK_BEGIN

class Rect
{
public:
	Rect();
	~Rect();
	Rect(const float& x, const float& y, const float& width, const float& height);

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

	float getMinX() const;
	float getMidX() const;
	float getMaxX() const; 

	float getMinY() const;
	float getMidY() const;
	float getMaxY() const;

	// Compare two Rect 
	bool equals(const Rect& rect) const;
	// Check if the point is contained in Rect
	bool containsPoint(const Vec2& point) const; 

	static const Rect ZERO;

private:
	// Delare coordinate top-left
	float _x, _y;

	// Delare width-height
	float _width, _height;

};

NS_JK_END

#endif // __RECT_H__
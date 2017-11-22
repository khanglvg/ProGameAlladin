#ifndef __SIZE_H__

#define __SIZE_H__
#include "definitions.h"

NS_JK_BEGIN

class Size
{
public:
	Size();
	Size(const float& width, const float& height);
	~Size();

#pragma region GET-SET
	float getWidth() const;
	void setWidth(const float& width);
	float getHeight() const;
	void setHeight(const float& height);
#pragma endregion 

private:
	float _width;
	float _height;
	
};

NS_JK_END

#endif __SIZE_H__

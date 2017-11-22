#include "Camera.h"

US_NS_JK


Camera::Camera(const float& width, const float& height):Node()
{
	_isStop = false;
	_width = width;
	_height = height;
	_startX = SCREEN_WIDTH / 2;;
	_startY = SCREEN_HEIGHT / 2;
	setScale(Vec2(-1, -1));
}

Camera::~Camera()
{	
}

void Camera::update()
{
	//update camera
}

void Camera::release()
{
	delete this;
}


#pragma region GET-SET
float Camera::getWidth() const
{
	return _width;
}

void Camera::setWidth(const float& width)
{
	_width = width;
}

float Camera::getHeight() const
{
	return _height;
}

void Camera::setHeight(const float& height)
{
	_height = height;
}

void Camera::stop()
{
	_isStop = true;
}

#pragma endregion 



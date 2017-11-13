#include "Camera.h"

US_NS_JK

Camera* Camera::_instance = nullptr;

Camera::Camera():_vx(0.0f), _vy(0.0f), _isPause(false)
{
}

Camera::~Camera()
{
}

Camera* Camera::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Camera();
	}

	return _instance;
}


#pragma region GET-SET
float Camera::getVX() const
{
	return _vx;
}

void Camera::setVX(const float& vx)
{
	_vx = vx;
}

float Camera::getVY() const
{
	return _vy;
}

void Camera::setVY(const float& vy)
{
	_vy = vy;
}

Vec2 Camera::getPosition() const
{
	return _position;
}

void Camera::setPosition(const Vec2& position)
{
	_position = position;
}

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
#pragma endregion 


void Camera::Update(float time)
{
	_position.x += _vx*time;
	_position.y += _vy*time;
}

void Camera::Stop()
{
	_isPause = true;
}

void Camera::Move()
{
	_isPause = false;
}

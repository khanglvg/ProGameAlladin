#include "Camera.h"
#include "Graphics.h"
#include "Input.h"
US_NS_JK

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
}

Camera::Camera(const float& width, const float& height, const float& angle, const Vec2& scaleFactors):Node()
{
	this->_width = width;
	this->_height = height;
	this->_angle = angle;
	this->_scaleFactors = scaleFactors;

	D3DXMatrixOrthoLH(&_orthographicMatrix, width, -height, 0.0f, 1.0f);

	D3DXMatrixIdentity(&_identityMatrix);

	_isUp = false;
}

Camera::~Camera()
{	
}

Camera* Camera::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new Camera(SCREEN_WIDTH,SCREEN_HEIGHT ,0 ,Vec2(0.8,0.8));
	}
	return _instance;
}

void Camera::update()
{
	// Camera's position
	int cameraX = this->_width / 2;
	int cameraY = this->_height / 2;

	if (this->_following && _isUp == false)
	{
		cameraX = this->_following->getPosition().getX() + 150;
		cameraY = this->_following->getPosition().getY() - 70 - 150;
	}
	else if (this->_following && _isUp != false)
	{
		cameraX = this->_following->getPosition().getX() + 150;
		cameraY = this->_following->getPosition().getY() - 70 - 50;
	}


	this->_viewMatrix = D3DXMATRIX(
		_scaleFactors.getX() * cos(_angle), _scaleFactors.getX() * sin(_angle), 0, 0,
		-_scaleFactors.getY() * sin(_angle), _scaleFactors.getY() * cos(_angle), 0, 0,
		0, 0, 1, 0,
		-cameraX * _scaleFactors.getX() * cos(_angle) + cameraY * _scaleFactors.getY() * sin(_angle), -cameraX * _scaleFactors.getY() * sin(_angle) - cameraY * _scaleFactors.getY() * cos(_angle), 0, 1
	);

}

void Camera::release()
{
	if(this->getInstance() != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}

void Camera::follow(Node* player)
{
	this->_following = player;
}

Node* Camera::nodeIsFollowing() const
{
	if(isFollowing())
	{
		return _following;
	}
	return nullptr;
}

bool Camera::isFollowing() const
{
	return this->_following != nullptr;
}

void Camera::unFollow()
{
	this->_following = nullptr;
}

void Camera::setTransform(Graphics* graphics) const
{
	graphics->getDevice()->SetTransform(D3DTS_PROJECTION, &_orthographicMatrix);
	graphics->getDevice()->SetTransform(D3DTS_WORLD, &_identityMatrix);
	graphics->getDevice()->SetTransform(D3DTS_VIEW, &_viewMatrix);
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

bool Camera::isUp() const
{
	return _isUp;
}

void Camera::setUp(const bool& isUp)
{
	_isUp = isUp;
}
#pragma endregion 



D3DXMATRIX Camera::convertToDirectMatrix(const Matrix &matrix)
{
	D3DXMATRIX d3DxMatrix;

	d3DxMatrix._11 = matrix.get11();
	d3DxMatrix._12 = matrix.get12();
	d3DxMatrix._13 = matrix.get13();
	d3DxMatrix._14 = matrix.get14();

	d3DxMatrix._21 = matrix.get21();
	d3DxMatrix._22 = matrix.get22();
	d3DxMatrix._23 = matrix.get23();
	d3DxMatrix._24 = matrix.get24();

	d3DxMatrix._31 = matrix.get31();
	d3DxMatrix._32 = matrix.get32();
	d3DxMatrix._33 = matrix.get33();
	d3DxMatrix._34 = matrix.get34();

	d3DxMatrix._41 = matrix.get41();
	d3DxMatrix._42 = matrix.get42();
	d3DxMatrix._43 = matrix.get43();
	d3DxMatrix._44 = matrix.get44();

	return d3DxMatrix;
}

Rect Camera::getRect()
{
	int cameraX = this->_width / 2;
	int cameraY = this->_height / 2;

	if (this->_following)
	{
		cameraX = this->_following->getPosition().getX();
		cameraY = this->_following->getPosition().getY();
	}
	return Rect(cameraX, cameraY, getWidth(), getHeight());
}


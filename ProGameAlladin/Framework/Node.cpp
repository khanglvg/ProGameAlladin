#include "Node.h"

US_NS_JK

Node::Node()
{
	_origin.x = 0.0f;
	_origin.y = 0.0f;

	_position.x = 0.0f;
	_position.y = 0.0f;

	_origin.x = 0.0f;
	_origin.y = 0.0f;

	_rotation = 0.0f;

	_scale.x = 1;
	_scale.y = 1;

}

Node::Node(const Vec2& origin, const Vec2& position, const float& rotation, const Vec2& scale)
{
	_origin = origin;
	_position = position;
	_rotation = rotation;
	_scale = scale;
}


Node::~Node()
{
}


#pragma region Get-Set
Vec2 Node::getPosition() const
{
	return _position;
}

void Node::setPosition(const Vec2& position)
{
	_position.x = position.x;
	_position.y = position.y;
}

float Node::getRotation() const
{
	return _rotation;
}

void Node::setRotation(const float& rotation)
{
	_rotation = rotation;
}

Vec2 Node::getScale() const
{
	return _scale;
}

void Node::setScale(const Vec2& scale)
{
	_scale.x = scale.x;
	_scale.y = scale.y;
}

Vec2 Node::getOrigin() const
{
	return _origin;
}

void Node::setOrigin(const Vec2& origin)
{
	_origin.x = origin.x;
	_origin.y = origin.y;
}

Vec2 Node::getVelocity() const
{
	return _velocity;
}

void Node::setVelocity(const Vec2& velocity)
{
	_velocity = velocity;
}


Matrix Node::getTransformMatrix() const
{
	const auto matrixTranslation = Matrix::getTranslationMatrix(_position.x, _position.y);
	const auto matrixRotation = Matrix::getMatrixRotationZ(_rotation);
	const auto matrixScaling = Matrix::getScalingMatrix(_scale.x, _scale.y);

	return matrixScaling*matrixRotation*matrixTranslation;
}

void Node::update()
{
	// Input: check if the key is pressed
}

void Node::release()
{
}

void Node::render()
{
}

void Node::init()
{

}


#pragma endregion 



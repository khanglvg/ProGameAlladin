#include "RigidBody.h"

US_NS_JK

RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
}


#pragma region GET-SET
Vec2 RigidBody::getPosition() const
{
	return _position;
}

void RigidBody::setPosition(const Vec2& position)
{
	_position = position;
}

Vec2 RigidBody::getVelocity() const
{
	return _velocity;
}

void RigidBody::setVelocity(const Vec2& velocity)
{
	_velocity = velocity;
}

int RigidBody::getBodyType() const
{
	return _bodyType;
}

void RigidBody::setBodyType(const int& bodyType)
{
	_bodyType = bodyType;
}

float RigidBody::getDensity() const
{
	return _density;
}

void RigidBody::setDensity(const float& density)
{
	_density = density;
}

float RigidBody::getRestitution() const
{
	return _restitution;
}

void RigidBody::setRestitution(const float& restitution)
{
	_restitution = restitution;
}

float RigidBody::getGravityScale() const
{
	return _gravityScale;
}

void RigidBody::setGravityScale(const float& gravityScale)
{
	_gravityScale = gravityScale;
}

float RigidBody::getForces() const
{
	return _forces;
}

void RigidBody::setForces(const float& forces)
{
	_forces = forces;
}

float RigidBody::getImpulse() const
{
	return _impulse;
}

void RigidBody::setImpulse(const float& impulse)
{
	_impulse = impulse;
}

Rect RigidBody::getShape() const
{
	return _shape;
}

void RigidBody::setShape(const Rect& shape)
{
	_shape = shape; 
}
#pragma endregion 
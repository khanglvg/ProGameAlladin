#include "RigidBody.h"
#include "PhysicsManager.h"

US_NS_JK

RigidBody::RigidBody()
{
	PhysicsManager::getIntance()->attachRigidbody(this);
}

RigidBody::RigidBody(	const Vec2& position,
						const Vec2& velocity, 
						const int& bodyType, 
						const float& density,
						const float& restitution, 
						const float& gravityScale, 
						const Vec2& forces, 
						const float& impulse, 
						const Vec2& offset,
						const Size& size)
{
	_position = position;
	_velocity = velocity;
	_bodyType = bodyType;
	_density = density;
	_restitution = restitution;
	_gravityScale = gravityScale;
	_forces = forces;
	_impulse = impulse;
	_offset = offset;
	_size = size;
	PhysicsManager::getIntance()->attachRigidbody(this);
}

RigidBody::~RigidBody()
{
	PhysicsManager::getIntance()->detachRigidbody(this);
}

const vector<string>& RigidBody::getCollidingBodies() const
{
	return _collidingBodies;
}

void RigidBody::setTag(const string& tag)
{
	_tag=tag;
}
string RigidBody::getTag() const
{
	return _tag;
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

Vec2 RigidBody::getForces() const
{
	return _forces;
}

void RigidBody::setForces(const Vec2& forces)
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

Vec2 RigidBody::getOffset() const
{
	return _offset;
}

void RigidBody::setOffset(const Vec2& offset)
{
	_offset = offset; 
}

Size RigidBody::getSize() const
{
	return _size;
}

void RigidBody::setSize(const Size& size)
{
	_size = size;
}


#pragma endregion 

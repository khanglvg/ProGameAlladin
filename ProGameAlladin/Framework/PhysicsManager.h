#ifndef __PHYSICSMANAGER_H__

#define __PHYSICSMANAGER_H__

#include "definitions.h"
#include "Vec2.h"
#include "RigidBody.h"


NS_JK_BEGIN
class PhysicsManager
{
public:
	PhysicsManager();

	~PhysicsManager();

	void resolveCollision(RigidBody& a, RigidBody& b) const;

	static float dotProduct(const Vec2& v1, const Vec2& v2);

	void positionalCorrection(RigidBody& a, RigidBody& b) const;
private:
	// hướng va chạm
	Vec2 _collisionNormal;

	// độ sâu của va chạm
	float _penetration;
};

NS_JK_END

#endif __PHYSICSMANAGER_H__
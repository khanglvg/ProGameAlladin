#ifndef __PHYSICSMANAGER_H__

#define __PHYSICSMANAGER_H__

#include "definitions.h"
#include "Vec2.h"
#include "RigidBody.h"


NS_JK_BEGIN
typedef struct Manifold
{
	RigidBody *rigid1;
	RigidBody *rigid2;
	// độ sâu của va chạm
	float penetration;
	// hướng va chạm
	Vec2 collisionNormal;

};

class PhysicsManager
{
public:
	PhysicsManager();

	~PhysicsManager();

	void attachRigidbody(RigidBody *rigidbody);

	void detachRigidbody(RigidBody *rigidbody);

	void resolveCollision(Manifold &manifold) const;

	static float dotProduct(const Vec2& v1, const Vec2& v2);

	void positionalCorrection(const Manifold& manifold) const;

	void update();

	bool AABBvAABB(RigidBody* a, RigidBody *b, Manifold& manifold);

	float sweptAABB(RigidBody* a, RigidBody *b, Manifold& manifold);

	Vec2 getCollisionNormal() const;

	void setCollisionNormal(Manifold manifold);

	static PhysicsManager* getIntance();
private:
	Vec2 _collisionNormal;

	std::vector<RigidBody*> _rigidBodies;

	static PhysicsManager* _instance;
};

NS_JK_END

#endif __PHYSICSMANAGER_H__
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

	void update();

	bool AABBvAABB(RigidBody* a, RigidBody *b, Manifold& manifold);

	float sweptAABB(RigidBody* a, RigidBody *b, Manifold& manifold) const;

	Vec2 getCollisionNormal() const;

	void setCollisionNormal(Manifold manifold);

	bool isColliding(Manifold& manifold) const;

	void setBeginLv1(const bool& isLv1);

	void setInBoss(const bool& isInBoss);
	static PhysicsManager* getIntance();
private:
	Vec2 _collisionNormal;

	std::vector<RigidBody*> _rigidBodies;

	static PhysicsManager* _instance;

	bool _isBeginLv1 = true;
	bool _isInBoss = false;
};

NS_JK_END

#endif __PHYSICSMANAGER_H__
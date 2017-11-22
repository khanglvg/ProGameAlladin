#include "PhysicsManager.h"
#include "GameManager.h"
US_NS_JK


PhysicsManager* PhysicsManager::_instance = nullptr;

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::attachRigidbody(RigidBody* rigidbody)
{
	_rigidBodies.push_back(rigidbody);
}

void PhysicsManager::detachRigidbody(RigidBody* rigidbody)
{
	const auto rb = std::find(_rigidBodies.begin(), _rigidBodies.end(), rigidbody);
	_rigidBodies.erase(rb);
}

void PhysicsManager::update()
{
	for(auto rigid : _rigidBodies)
	{
		const auto deltaTime = GameManager::getInstance()->getDeltaTime();
		
		const auto mass = rigid->getDensity() * rigid->getSize().getWidth()*rigid->getSize().getHeight();

		// v = v + (1 / m * F) * dt; 
		rigid->setVelocity(Vec2(rigid->getVelocity() + rigid->getForces()*(1/mass)*deltaTime) + Vec2(0,400.0f) * rigid->getGravityScale());

		// x = x + v * dt;
		rigid->setPosition(Vec2(rigid->getPosition() + rigid->getVelocity()*deltaTime));		
	}

	for(auto it1 = _rigidBodies.begin(); it1 != _rigidBodies.end(); ++it1)
	{
		for(auto it2 = it1 +1; it2 != _rigidBodies.end(); ++it2)
		{
			Manifold manifold;
			if(AABBvAABB(*it1, *it2, manifold))
			{
				resolveCollision(manifold);
			}
		}
	}
}

bool PhysicsManager::AABBvAABB(RigidBody* a, RigidBody *b, Manifold& manifold) const
{
	manifold.rigid1 = a;
	manifold.rigid2 = b;

	// Vector from a to b
	auto vecAtoB = b->getPosition() - a->getPosition();

	// Tính phân nửa chiều rộng (x) của mỗi body
	auto a_extent = a->getSize().getWidth() / 2;
	auto b_extent = b->getSize().getWidth() / 2;

	// Tính phần đè lên nhau theo trục x
	const auto x_overlap = a_extent + b_extent - abs(vecAtoB.getX());

	if (x_overlap > 0)
	{
		// Tính phân nửa chiều dài (y) của mỗi body
		a_extent = a->getSize().getHeight() / 2;
		b_extent = b->getSize().getHeight() / 2;

		// Tính phần đè lên nhau theo trục y
		const auto y_overlap = a_extent + b_extent - abs(vecAtoB.getY());

		if(y_overlap > 0)
		{
			// Tính toán xem phần đè lên nhau nào ít hơn thì hướng va chạm sẽ theo chiều đó
			if (x_overlap < y_overlap)
			{
				if(vecAtoB.getX() < 0)
					manifold.collisionNormal = Vec2(-1, 0);
				else
					manifold.collisionNormal = Vec2(1, 0);
				manifold.penetration = x_overlap;
				return true;
			}
			else
			{
				if (vecAtoB.getY() < 0)
					manifold.collisionNormal = Vec2(0, -1);
				else
					manifold.collisionNormal = Vec2(0, 1);
				manifold.penetration = y_overlap;
				return true;
			}
		}
	}

	return false;
}


void PhysicsManager::resolveCollision(const Manifold &manifold) const
{
	// Calculate relative velocity
	const auto relativeVelocity = manifold.rigid2->getVelocity() - manifold.rigid1->getVelocity();
	
	// Calculate
	const auto velocityAlongNormal = dotProduct(relativeVelocity, manifold.collisionNormal); 

	if (velocityAlongNormal > 0)
		return;

	const auto restitution = min(manifold.rigid2->getRestitution(), manifold.rigid1->getRestitution());

	// Calculate impulse scalar (hệ số xung lực)
	auto j = -(1 + restitution)*velocityAlongNormal;
	
	// j /= 1 / A.mass + 1 / B.mass
	// mass = density*squared
	// squared = width*height
	const auto massA = manifold.rigid1->getDensity() * manifold.rigid1->getSize().getWidth()*manifold.rigid1->getSize().getHeight();
	const auto massB = manifold.rigid2->getDensity() * manifold.rigid2->getSize().getWidth()*manifold.rigid2->getSize().getHeight();
	j /= 1 / (massA) + 1 / (massB);

	// Apply impulse
	const auto impulse = manifold.collisionNormal * j;

	// Calculate sum of mass
	const auto massSum = massA + massB;

	// ratio: tỉ lệ khối lượng
	auto ratio = massA / massSum;

	if(manifold.rigid1->getBodyType() == DYNAMIC)
	{
		manifold.rigid1->setVelocity(manifold.rigid1->getVelocity() - impulse/massA);
	}
	
	ratio = massB / massSum;
	if (manifold.rigid2->getBodyType() == DYNAMIC)
	{
		manifold.rigid2->setVelocity(manifold.rigid2->getVelocity() + impulse/massB);
	}
	
	positionalCorrection(manifold);
}



float PhysicsManager::dotProduct(const Vec2& v1, const Vec2& v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

void PhysicsManager::positionalCorrection(const Manifold& manifold) const
{
	const auto massA = manifold.rigid1->getDensity() * manifold.rigid1->getSize().getWidth()*manifold.rigid1->getSize().getHeight();
	const auto massB = manifold.rigid2->getDensity() * manifold.rigid2->getSize().getWidth()*manifold.rigid2->getSize().getHeight();

	const auto inverseMassA = 1 / massA;
	const auto inverseMassB = 1 / massB;

	const float percent = 0.2; // usually 20% to 80%

	const float slop = 0.01; // usually 0.01 to 0.1

	const auto correction = manifold.collisionNormal * percent* max(manifold.penetration - slop, 0.0f) / (inverseMassA + inverseMassB);

	if (manifold.rigid1->getBodyType() == DYNAMIC)
	{
		manifold.rigid1->setPosition(Vec2(manifold.rigid1->getPosition() - correction * inverseMassA));
	}
	if (manifold.rigid2->getBodyType() == DYNAMIC)
	{
		manifold.rigid2->setPosition(Vec2(manifold.rigid2->getPosition() + correction * inverseMassB));
	}

}



PhysicsManager* PhysicsManager::getIntance()
{
	if (_instance == nullptr)
	{
		_instance = new PhysicsManager();
	}

	return _instance;
}

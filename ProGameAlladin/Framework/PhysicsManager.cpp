#include "PhysicsManager.h"
US_NS_JK

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::resolveCollision(RigidBody& a, RigidBody& b) const
{
	// Calculate relative velocity
	const auto relativeVelocity = b.getVelocity() - a.getVelocity();

	// Calculate
	const auto velocityAlongNormal = dotProduct(relativeVelocity, _collisionNormal); 

	if (velocityAlongNormal > 0)
		return;

	const auto restitution = min(b.getRestitution(), a.getRestitution());

	// Calculate impulse scalar (hệ số xung lực)
	auto j = -(1 + restitution)*velocityAlongNormal;
	
	// j /= 1 / A.mass + 1 / B.mass
	// mass = density*squared
	// squared = width*height
	const auto massA = a.getDensity() * a.getShape().getWidth()*a.getShape().getHeight();
	const auto massB = b.getDensity() * b.getShape().getWidth()*b.getShape().getHeight();
	j /= 1 / (massA) + 1 / (massB);

	// Apply impulse
	const auto impulse = j * _collisionNormal;

	// Calculate sum of mass
	const auto massSum = massA + massB;

	// ratio: tỉ lệ khối lượng
	auto ratio = massA / massSum;

	// A.velocity -= ratio * impulse
	a.setVelocity(a.getVelocity() - ratio*impulse);

	ratio = massB / massSum;

	// B.velocity += ratio * impulse
	b.setVelocity(b.getVelocity() + ratio*impulse);
}



float PhysicsManager::dotProduct(const Vec2& v1, const Vec2& v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

void PhysicsManager::positionalCorrection(RigidBody& a, RigidBody& b) const
{
	const auto massA = a.getDensity() * a.getShape().getWidth()*a.getShape().getHeight();
	const auto massB = b.getDensity() * b.getShape().getWidth()*b.getShape().getHeight();

	const auto inverseMassA = 1 / massA;
	const auto inverseMassB = 1 / massB;

	const float percent = 0.2; // usually 20% to 80%

	const float slop = 0.01; // usually 0.01 to 0.1

	const auto correction = max(_penetration - slop, 0.0f) / (inverseMassA + inverseMassB) * percent * _collisionNormal;
	
	a.setPosition(Vec2(a.getPosition() - inverseMassA * correction));
	b.setPosition(Vec2(b.getPosition() + inverseMassB * correction));
}

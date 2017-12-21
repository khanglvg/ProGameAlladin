#include "TransformIdleState.h"
#include "TransformAttackState.h"
#include "../Jafar.h"
#include "../../../../Framework/GameManager.h"

US_NS_JK

TransformIdleState::TransformIdleState()
{
}

TransformIdleState::TransformIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("Transform-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

TransformIdleState::~TransformIdleState()
{
}

void TransformIdleState::onUpdate()
{
	auto jafar = static_cast<Jafar*>(_enemy);
}

void TransformIdleState::onExit()
{
}

EnemyState * TransformIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new TransformAttackState(_enemy);
	}

	return nullptr;
}

 
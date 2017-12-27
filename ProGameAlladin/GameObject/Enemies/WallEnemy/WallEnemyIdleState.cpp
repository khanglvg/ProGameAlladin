#include "WallEnemyIdleState.h"
#include "WallEnemyAttackState.h"
#include "WallEnemy.h"

US_NS_JK

WallEnemyIdleState::WallEnemyIdleState()
{
}

WallEnemyIdleState::WallEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("WallEnemy-Idle");
	_enemy->getRigidBody()->setActive(false);
}

WallEnemyIdleState::~WallEnemyIdleState()
{
}

void WallEnemyIdleState::onUpdate()
{
	auto wallEnemy = static_cast<WallEnemy*>(_enemy);
}

void WallEnemyIdleState::onExit()
{
}

EnemyState * WallEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInViewRange())
	{
		return new WallEnemyAttackState(_enemy);
	}
	return nullptr;
}
 
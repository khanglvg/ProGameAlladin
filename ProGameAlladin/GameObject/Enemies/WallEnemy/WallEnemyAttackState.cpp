#include "WallEnemyAttackState.h"
#include "WallEnemy.h"
#include "WallEnemyIdleState.h"

US_NS_JK

WallEnemyAttackState::WallEnemyAttackState()
{
}

WallEnemyAttackState::WallEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("WallEnemy-Attack");
}

WallEnemyAttackState::~WallEnemyAttackState()
{
}

void WallEnemyAttackState::onUpdate()
{
	auto wallEnemy = static_cast<WallEnemy*>(_enemy);
}

void WallEnemyAttackState::onExit()
{
}

EnemyState * WallEnemyAttackState::checkTransition()
{
	if (!_enemy->isTargetInViewRange())
	{
		if (_enemy->getIndex() >= 8)
		{
			return new WallEnemyIdleState(_enemy);
		}
	}
	return nullptr;
}
 
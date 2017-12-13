#include "HideEnemyIdleState.h"
#include "HideEnemyAttackState.h"
#include "HideEnemyWalkState.h"
#include "HideEnemy.h"

US_NS_JK

HideEnemyIdleState::HideEnemyIdleState()
{
}

HideEnemyIdleState::HideEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("HideEnemy-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

HideEnemyIdleState::~HideEnemyIdleState()
{
	auto hideEnemy = static_cast<HideEnemy*>(_enemy);
}

void HideEnemyIdleState::onExit()
{
}

EnemyState * HideEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new HideEnemyAttackState(_enemy);
	}
	if (_enemy->isTargetInViewRange())
	{
		if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
		{
			return new HideEnemyWalkState(_enemy);
		}
		if (_enemy->isRight() && _enemy->isAllowMoveRight())
		{
			return new HideEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
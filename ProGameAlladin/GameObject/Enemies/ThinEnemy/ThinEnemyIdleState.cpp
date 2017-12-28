#include "ThinEnemyIdleState.h"
#include "ThinEnemyWalkState.h"
#include "ThinEnemyAttackState.h"
#include "ThinEnemyInAttackedState.h"
#include "ThinEnemy.h"

US_NS_JK

ThinEnemyIdleState::ThinEnemyIdleState()
{
}

ThinEnemyIdleState::ThinEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("ThinEnemy-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

ThinEnemyIdleState::~ThinEnemyIdleState()
{
}

void ThinEnemyIdleState::onUpdate()
{
	auto thinEnemy = static_cast<ThinEnemy*>(_enemy);
}

void ThinEnemyIdleState::onExit()
{
}

EnemyState * ThinEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new ThinEnemyAttackState(_enemy);
	}
	if (_enemy->isTargetInViewRange())
	{
		if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
		{
			return new ThinEnemyWalkState(_enemy);
		}
		if (_enemy->isRight() && _enemy->isAllowMoveRight())
		{
			return new ThinEnemyWalkState(_enemy);
		}
	}

	if (_enemy->isAttacked())
	{
		return new ThinEnemyInAttackedState(_enemy);
	}
	return nullptr;
}
 
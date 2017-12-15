#include "BigEnemyIdleState.h"
#include "BigEnemyAttackState.h"
#include "BigEnemyWalkState.h"
#include "BigEnemyDefiantState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyIdleState::BigEnemyIdleState()
{
}

BigEnemyIdleState::BigEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

BigEnemyIdleState::~BigEnemyIdleState()
{
}

void BigEnemyIdleState::onUpdate()
{
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);
}

void BigEnemyIdleState::onExit()
{
}

EnemyState * BigEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new BigEnemyAttackState(_enemy);
	}
	if (_enemy->isTargetInViewRange())
	{
		if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
		{
			return new BigEnemyWalkState(_enemy);
		}
		if (_enemy->isRight() && _enemy->isAllowMoveRight())
		{
			return new BigEnemyWalkState(_enemy);
		}
		return new BigEnemyDefiantState(_enemy);
	}
	return nullptr;
}
 
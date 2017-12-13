#include "BigEnemyAttackState.h"
#include "BigEnemy.h"
#include "BigEnemyWalkState.h"
#include "BigEnemyIdleState.h"

US_NS_JK

BigEnemyAttackState::BigEnemyAttackState()
{
}

BigEnemyAttackState::BigEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-AttackHigh");
	_enemy->setVelocity(Vec2(0, 0));
}

BigEnemyAttackState::~BigEnemyAttackState()
{
}

void BigEnemyAttackState::onUpdate()
{
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}
}

void BigEnemyAttackState::onExit()
{

}

EnemyState * BigEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() >= 4)
		{
			return new BigEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
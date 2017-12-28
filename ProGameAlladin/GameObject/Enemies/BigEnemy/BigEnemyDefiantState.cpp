#include "BigEnemyAttackState.h"
#include "BigEnemyDefiantState.h"
#include "BigEnemy.h"
#include "BigEnemyWalkState.h"
#include "BigEnemyIdleState.h"
#include "BigEnemyInAttackedState.h"

US_NS_JK

BigEnemyDefiantState::BigEnemyDefiantState()
{
}

BigEnemyDefiantState::BigEnemyDefiantState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Defiant");
	_enemy->setVelocity(Vec2(0, 0));
}

BigEnemyDefiantState::~BigEnemyDefiantState()
{
}

void BigEnemyDefiantState::onUpdate()
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

void BigEnemyDefiantState::onExit()
{

}

EnemyState * BigEnemyDefiantState::checkTransition()
{
	if (!_enemy->isTargetInViewRange())
	{
		if  (_enemy->getIndex() == 2)
		{
			return new BigEnemyIdleState(_enemy);
		}
	}
	if (_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() == 2)
		{
			return new BigEnemyAttackState(_enemy);
		}
	}

	if (_enemy->isAttacked())
	{
		return new BigEnemyInAttackedState(_enemy);
	}
	return nullptr;
}
 
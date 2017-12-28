#include "BigEnemyFiredState.h"
#include "BigEnemyIdleState.h"
#include "BigEnemyInAttackedState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyFiredState::BigEnemyFiredState()
{
}

BigEnemyFiredState::BigEnemyFiredState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Fired");
}

BigEnemyFiredState::~BigEnemyFiredState()
{
}

void BigEnemyFiredState::onUpdate()
{
}

void BigEnemyFiredState::onExit()
{

}

EnemyState * BigEnemyFiredState::checkTransition()
{
	if (!_enemy->isInFire())
	{
		return new BigEnemyIdleState(_enemy);
	}
	if (_enemy->isAttacked())
	{
		return new BigEnemyInAttackedState(_enemy);
	}
	return nullptr;
}
 
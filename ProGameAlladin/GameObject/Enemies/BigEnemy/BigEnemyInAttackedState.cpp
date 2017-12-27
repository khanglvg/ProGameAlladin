#include "BigEnemyInAttackedState.h"
#include "BigEnemyIdleState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyInAttackedState::BigEnemyInAttackedState()
{
}

BigEnemyInAttackedState::BigEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Attacked");
	_enemy->setVelocity(Vec2(0,0));
}

BigEnemyInAttackedState::~BigEnemyInAttackedState()
{
}

void BigEnemyInAttackedState::onUpdate()
{
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);
}

void BigEnemyInAttackedState::onExit()
{
}

EnemyState * BigEnemyInAttackedState::checkTransition()
{
	if (_enemy->getIndex() == 6)
	{
		return new BigEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
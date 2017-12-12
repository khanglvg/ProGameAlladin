#include "BigEnemyInAttackedState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyInAttackedState::BigEnemyInAttackedState()
{
}

BigEnemyInAttackedState::BigEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	auto bigEnemy = static_cast<BigEnemy*>(enemy);
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Attacked");
}

BigEnemyInAttackedState::~BigEnemyInAttackedState()
{
}

void BigEnemyInAttackedState::onUpdate()
{
	auto thinEnemy = static_cast<BigEnemy*>(_enemy);
}

void BigEnemyInAttackedState::onExit()
{
}

EnemyState * BigEnemyInAttackedState::checkTransition()
{
	return nullptr;
}
 
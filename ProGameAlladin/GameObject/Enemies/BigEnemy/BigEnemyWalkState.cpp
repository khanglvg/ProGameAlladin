#include "BigEnemyWalkState.h"
#include "BigEnemy.h"
#include "BigEnemyAttackState.h"
#include "BigEnemyDefiantState.h"

US_NS_JK

BigEnemyWalkState::BigEnemyWalkState()
{
}

BigEnemyWalkState::BigEnemyWalkState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Walk)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Walk");
}

BigEnemyWalkState::~BigEnemyWalkState()
{
}

void BigEnemyWalkState::onUpdate()
{
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);

	if (!_enemy->isRight() && _enemy->isAllowMoveLeft() && _enemy->getIndex()-1 == 0)
	{
		bigEnemy->setScale(Vec2(1, 1));
		bigEnemy->setVelocity(Vec2(-50, bigEnemy->getVelocity().getY()));
	}

	else if (_enemy->isRight() && _enemy->isAllowMoveRight() && _enemy->getIndex()-1 == 0)
	{
		bigEnemy->setScale(Vec2(-1, 1));
		bigEnemy->setVelocity(Vec2(50, bigEnemy->getVelocity().getY()));
	}
}

void BigEnemyWalkState::onExit()
{
}

EnemyState * BigEnemyWalkState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new BigEnemyAttackState(_enemy);
	}
	if (!_enemy->isRight() && !_enemy->isAllowMoveLeft() && _enemy->getIndex() == 0)
	{
		return new BigEnemyDefiantState(_enemy);
	}
	if (_enemy->isRight() && !_enemy->isAllowMoveRight() && _enemy->getIndex() == 0)
	{
		return new BigEnemyDefiantState(_enemy);
	}
	if (!_enemy->isTargetInViewRange() && _enemy->getIndex() == 0)
	{
		return new BigEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
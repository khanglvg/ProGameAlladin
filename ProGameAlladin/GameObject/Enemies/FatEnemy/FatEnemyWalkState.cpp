#include "FatEnemyWalkState.h"
#include "FatEnemy.h"
#include "FatEnemyAttackState.h"

US_NS_JK

FatEnemyWalkState::FatEnemyWalkState()
{
}

FatEnemyWalkState::FatEnemyWalkState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Walk)
{
	_enemy = enemy;
	_enemy->setActionName("FatEnemy-Walk");
}

FatEnemyWalkState::~FatEnemyWalkState()
{
}

void FatEnemyWalkState::onUpdate()
{
	auto fatEnemy = static_cast<FatEnemy*>(_enemy);

	if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
	{
		fatEnemy->setScale(Vec2(1, 1));
		fatEnemy->setVelocity(Vec2(-50, fatEnemy->getVelocity().getY()));
	}

	else if (_enemy->isRight() && _enemy->isAllowMoveRight())
	{
		fatEnemy->setScale(Vec2(-1, 1));
		fatEnemy->setVelocity(Vec2(50, fatEnemy->getVelocity().getY()));
	}
}

void FatEnemyWalkState::onExit()
{
}

EnemyState * FatEnemyWalkState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new FatEnemyAttackState(_enemy);
	}
	if (!_enemy->isRight() && !_enemy->isAllowMoveLeft())
	{
		return new FatEnemyIdleState(_enemy);
	}
	if (_enemy->isRight() && !_enemy->isAllowMoveRight())
	{
		return new FatEnemyIdleState(_enemy);
	}
	if (!_enemy->isTargetInViewRange())
	{
		return new FatEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
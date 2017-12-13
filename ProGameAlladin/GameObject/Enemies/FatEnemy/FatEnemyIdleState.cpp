#include "FatEnemyIdleState.h"
#include "FatEnemyAttackState.h"
#include "FatEnemyWalkState.h"
#include "FatEnemy.h"

US_NS_JK

FatEnemyIdleState::FatEnemyIdleState()
{
}

FatEnemyIdleState::FatEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("FatEnemy-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

FatEnemyIdleState::~FatEnemyIdleState()
{
}

void FatEnemyIdleState::onUpdate()
{
	auto fatEnemy = static_cast<FatEnemy*>(_enemy);
}

void FatEnemyIdleState::onExit()
{
}

EnemyState * FatEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new FatEnemyAttackState(_enemy);
	}
	if (_enemy->isTargetInViewRange())
	{
		if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
		{
			return new FatEnemyWalkState(_enemy);
		}
		if (_enemy->isRight() && _enemy->isAllowMoveRight())
		{
			return new FatEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
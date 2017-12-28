#include "FatEnemyIdleState.h"
#include "FatEnemyAttackState.h"
#include "FatEnemyWalkState.h"
#include "FatEnemy.h"
#include "../../../Framework/GameManager.h"

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

	if (_enemy->isNotAllowedMove())
	{
		_enemy->setActionName("FatEnemy-NotAllowedMove");
	}
}

void FatEnemyIdleState::onExit()
{
}

EnemyState * FatEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		if (_expect >= 0.5)
		{
			return new FatEnemyAttackState(_enemy);
		}
		else
		{
			_expect += GameManager::getInstance()->getDeltaTime();
			return nullptr;
		}
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
 
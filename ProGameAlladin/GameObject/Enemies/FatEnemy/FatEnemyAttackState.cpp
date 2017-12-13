#include "FatEnemyAttackState.h"
#include "FatEnemy.h"
#include "FatEnemyWalkState.h"
#include "FatEnemyIdleState.h"

US_NS_JK

FatEnemyAttackState::FatEnemyAttackState()
{
}

FatEnemyAttackState::FatEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("FatEnemy-Attack");
	_enemy->setVelocity(Vec2(0, 0));
}

FatEnemyAttackState::~FatEnemyAttackState()
{
}

void FatEnemyAttackState::onUpdate()
{
	auto fatEnemy = static_cast<FatEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}
}

void FatEnemyAttackState::onExit()
{

}

EnemyState * FatEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() >= 4)
		{
			return new FatEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
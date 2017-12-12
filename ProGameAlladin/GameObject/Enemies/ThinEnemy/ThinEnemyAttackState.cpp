#include "ThinEnemyAttackState.h"
#include "ThinEnemy.h"
#include "ThinEnemyWalkState.h"
#include "ThinEnemyIdleState.h"

US_NS_JK

ThinEnemyAttackState::ThinEnemyAttackState()
{
}

ThinEnemyAttackState::ThinEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("ThinEnemy-Attack");
	_enemy->setVelocity(Vec2(0, 0));
}

ThinEnemyAttackState::~ThinEnemyAttackState()
{
}

void ThinEnemyAttackState::onUpdate()
{
	auto thinEnemy = static_cast<ThinEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}
}

void ThinEnemyAttackState::onExit()
{
}

EnemyState * ThinEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() >= 5)
		{
			return new ThinEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
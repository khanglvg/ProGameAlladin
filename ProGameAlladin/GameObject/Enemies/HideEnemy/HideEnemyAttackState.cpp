#include "HideEnemyAttackState.h"
#include "HideEnemy.h"
#include "HideEnemyWalkState.h"
#include "HideEnemyIdleState.h"

US_NS_JK

HideEnemyAttackState::HideEnemyAttackState()
{
}

HideEnemyAttackState::HideEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("HideEnemy-Attack");
	_enemy->setVelocity(Vec2(0, 0));
}

HideEnemyAttackState::~HideEnemyAttackState()
{
}

void HideEnemyAttackState::onUpdate()
{
	auto hideEnemy = static_cast<HideEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(-1, 1));
	}
}

void HideEnemyAttackState::onExit()
{

}

EnemyState * HideEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() == 0)
		{
			return new HideEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
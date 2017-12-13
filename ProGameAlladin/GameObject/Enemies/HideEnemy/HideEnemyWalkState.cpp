#include "HideEnemyWalkState.h"
#include "HideEnemy.h"
#include "HideEnemyAttackState.h"

US_NS_JK

HideEnemyWalkState::HideEnemyWalkState()
{
}

HideEnemyWalkState::HideEnemyWalkState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Walk)
{
	_enemy = enemy;
	_enemy->setActionName("HideEnemy-Walk");
}

HideEnemyWalkState::~HideEnemyWalkState()
{
}

void HideEnemyWalkState::onUpdate()
{
	auto hideEnemy = static_cast<HideEnemy*>(_enemy);

	if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
	{
		hideEnemy->setScale(Vec2(-1, 1));
		hideEnemy->setVelocity(Vec2(-50, hideEnemy->getVelocity().getY()));
	}

	else if (_enemy->isRight() && _enemy->isAllowMoveRight())
	{
		hideEnemy->setScale(Vec2(1, 1));
		hideEnemy->setVelocity(Vec2(50, hideEnemy->getVelocity().getY()));
	}
}

void HideEnemyWalkState::onExit()
{
}

EnemyState * HideEnemyWalkState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new HideEnemyAttackState(_enemy);
	}
	if (!_enemy->isRight() && !_enemy->isAllowMoveLeft())
	{
		return new HideEnemyIdleState(_enemy);
	}
	if (_enemy->isRight() && !_enemy->isAllowMoveRight())
	{
		return new HideEnemyIdleState(_enemy);
	}
	if (!_enemy->isTargetInViewRange())
	{
		return new HideEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
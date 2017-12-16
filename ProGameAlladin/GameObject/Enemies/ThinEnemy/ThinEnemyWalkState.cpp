#include "ThinEnemyWalkState.h"
#include "ThinEnemy.h"
#include "ThinEnemyAttackState.h"

US_NS_JK

ThinEnemyWalkState::ThinEnemyWalkState()
{
}

ThinEnemyWalkState::ThinEnemyWalkState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Walk)
{
	_enemy = enemy;
	_enemy->setActionName("ThinEnemy-Walk");
}

ThinEnemyWalkState::~ThinEnemyWalkState()
{
}

void ThinEnemyWalkState::onUpdate()
{
	auto thinEnemy = static_cast<ThinEnemy*>(_enemy);

	if (!_enemy->isRight() && _enemy->isAllowMoveLeft() && _enemy->getIndex()-1 == 0)
	{
		thinEnemy->setScale(Vec2(1, 1));
		thinEnemy->setVelocity(Vec2(-50, thinEnemy->getVelocity().getY()));
	}

	else if (_enemy->isRight() && _enemy->isAllowMoveRight() && _enemy->getIndex()-1 == 0)
	{
		thinEnemy->setScale(Vec2(-1, 1));
		thinEnemy->setVelocity(Vec2(50, thinEnemy->getVelocity().getY()));
	}
}

void ThinEnemyWalkState::onExit()
{
}

EnemyState * ThinEnemyWalkState::checkTransition()
{
	if (_enemy->isTargetInAttackRange())
	{
		return new ThinEnemyAttackState(_enemy);
	}
	if (!_enemy->isRight() && !_enemy->isAllowMoveLeft() && _enemy->getIndex() == 0)
	{
		return new ThinEnemyIdleState(_enemy);
	}
	if (_enemy->isRight() && !_enemy->isAllowMoveRight() && _enemy->getIndex() == 0)
	{
		return new ThinEnemyIdleState(_enemy);
	}
	if (!_enemy->isTargetInViewRange() && _enemy->getIndex() == 0)
	{
		return new ThinEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
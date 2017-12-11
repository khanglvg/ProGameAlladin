#include "ThinEnemyWalkState.h"
#include "ThinEnemy.h"

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

	if (!_enemy->isRight() && _enemy->isAllowMoveLeft())
	{
		thinEnemy->setScale(Vec2(1, 1));
		thinEnemy->setVelocity(Vec2(-10, thinEnemy->getVelocity().getY()));
	}

	else if (_enemy->isRight() && _enemy->isAllowMoveRight())
	{
		thinEnemy->setScale(Vec2(-1, 1));
		thinEnemy->setVelocity(Vec2(10, thinEnemy->getVelocity().getY()));
	}
}

void ThinEnemyWalkState::onExit()
{
}

EnemyState * ThinEnemyWalkState::checkTransition()
{
	return nullptr;
}
 
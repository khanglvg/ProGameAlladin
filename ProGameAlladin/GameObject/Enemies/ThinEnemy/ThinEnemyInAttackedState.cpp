#include "ThinEnemyInAttackedState.h"
#include "ThinEnemy.h"

US_NS_JK

ThinEnemyInAttackedState::ThinEnemyInAttackedState()
{
}

ThinEnemyInAttackedState::ThinEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	auto thinEnemy = static_cast<ThinEnemy*>(enemy);
	_enemy = enemy;
	_enemy->setActionName("ThinEnemy-Attacked");
}

ThinEnemyInAttackedState::~ThinEnemyInAttackedState()
{
}

void ThinEnemyInAttackedState::onUpdate()
{
	auto thinEnemy = static_cast<ThinEnemy*>(_enemy);
}

void ThinEnemyInAttackedState::onExit()
{
}

EnemyState * ThinEnemyInAttackedState::checkTransition()
{
	if (!_enemy->getIsCollisionWithAladdin())
	{
		return new ThinEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
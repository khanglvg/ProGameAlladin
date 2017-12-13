#include "FatEnemyInAttackedState.h"
#include "FatEnemy.h"

US_NS_JK

FatEnemyInAttackedState::FatEnemyInAttackedState()
{
}

FatEnemyInAttackedState::FatEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	_enemy = enemy;
	_enemy->setActionName("FatEnemy-Attacked");
}

FatEnemyInAttackedState::~FatEnemyInAttackedState()
{
}

void FatEnemyInAttackedState::onUpdate()
{
	auto fatEnemy = static_cast<FatEnemy*>(_enemy);
}

void FatEnemyInAttackedState::onExit()
{
}

EnemyState * FatEnemyInAttackedState::checkTransition()
{
	return nullptr;
}
 
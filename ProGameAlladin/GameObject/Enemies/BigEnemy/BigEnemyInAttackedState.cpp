#include "BigEnemyInAttackedState.h"
#include "BigEnemyIdleState.h"
#include "BigEnemyFiredState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyInAttackedState::BigEnemyInAttackedState()
{
}

BigEnemyInAttackedState::BigEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-Attacked");
	_enemy->setVelocity(Vec2(0,0));
}

BigEnemyInAttackedState::~BigEnemyInAttackedState()
{
}

void BigEnemyInAttackedState::onUpdate()
{
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);
}

void BigEnemyInAttackedState::onExit()
{
}

EnemyState * BigEnemyInAttackedState::checkTransition()
{
	if (_enemy->getIndex() == 6)
	{
		if (_enemy->isTargetInViewRange() && _enemy->isInFire())
		{
			if (!_enemy->isRight())
			{
				_enemy->setVelocity(Vec2(-50, _enemy->getVelocity().getY()));
			}

			else if (_enemy->isRight())
			{
				_enemy->setVelocity(Vec2(50, _enemy->getVelocity().getY()));
			}
			return new BigEnemyFiredState(_enemy);
		}
		return new BigEnemyIdleState(_enemy);
	}
	return nullptr;
}
 
#include "BigEnemyAttackState.h"
#include "BigEnemy.h"
#include "BigEnemyWalkState.h"
#include "BigEnemyIdleState.h"

US_NS_JK

BigEnemyAttackState::BigEnemyAttackState()
{
}

BigEnemyAttackState::BigEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-AttackHigh");
	_enemy->setVelocity(Vec2(0, 0));
}

BigEnemyAttackState::~BigEnemyAttackState()
{
}

void BigEnemyAttackState::onUpdate()
{
	_isChange = false;
	auto _checkIndex = 0;
	if (_enemy->getActionName() == "BigEnemy-AttackLow")
	{
		_checkIndex = 3;
	}
	if (_enemy->getIndex() == _checkIndex)
	{
		switch (rand() % 2)
		{
		case 0:
			if (_enemy->getActionName() != "BigEnemy-AttackLow")
			{
				_isChange = true;
			}
			else _isChange = false;
			_enemy->setActionName("BigEnemy-AttackLow");
			break;
		case 1:
			if (_enemy->getActionName() != "BigEnemy-AttackHigh")
			{
				_isChange = true;
			}
			else _isChange = false;
			_enemy->setActionName("BigEnemy-AttackHigh");
			break;
		default:
			break;
		}
	}
	auto bigEnemy = static_cast<BigEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}
}

void BigEnemyAttackState::onExit()
{

}

EnemyState * BigEnemyAttackState::checkTransition()
{
	auto _checkIndex = 0;
	if (_enemy->getActionName() == "BigEnemy-AttackLow")
	{
		_checkIndex = 3;
	}
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() == _checkIndex)
		{
			return new BigEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
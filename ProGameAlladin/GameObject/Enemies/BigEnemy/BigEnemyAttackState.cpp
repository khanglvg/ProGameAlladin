#include "BigEnemyAttackState.h"
#include "BigEnemy.h"
#include "BigEnemyWalkState.h"
#include "BigEnemyIdleState.h"
#include "../../Framework/Scene.h"

US_NS_JK

BigEnemyAttackState::BigEnemyAttackState()
{
}

BigEnemyAttackState::BigEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("BigEnemy-AttackHigh");
	_enemy->setVelocity(Vec2(0, 0));

	_weapon = new Weapon(_enemy, _enemy->getRigidPosition(), Size(45, 30), Vec2(30, 12), "thinenemyknife");
	_weapon->setCurrentScene(_enemy->getCurrentScene());
	_weapon->getRigidBody()->setActive(true);

	_enemy->getCurrentScene()->addNode(_weapon);
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
		_enemy->setIsOwnerRight(true);
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
		_enemy->setIsOwnerRight(false);
	}
}

void BigEnemyAttackState::onExit()
{
	_weapon->getRigidBody()->setActive(false);
	_enemy->getCurrentScene()->removeNode(_weapon);
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
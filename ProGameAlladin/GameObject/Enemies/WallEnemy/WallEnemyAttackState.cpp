#include "WallEnemyAttackState.h"
#include "WallEnemy.h"
#include "WallEnemyIdleState.h"
#include "../../Weapons/PotToThrow.h"
#include "../../../Framework/Scene.h"

US_NS_JK

WallEnemyAttackState::WallEnemyAttackState()
{
}

WallEnemyAttackState::WallEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("WallEnemy-Attack");
	_enemy->getRigidBody()->setActive(true);
}

WallEnemyAttackState::~WallEnemyAttackState()
{
}

void WallEnemyAttackState::onUpdate()
{
	auto wallEnemy = static_cast<WallEnemy*>(_enemy);
		if (_enemy->getIndex() == 6)
		{
			if (!_isThrew)
			{
				const auto pot = new PotToThrow(_enemy, Vec2(_enemy->getRigidPosition().getX() + 5, _enemy->getRigidPosition().getY() + 28), Size(31, 25));
				pot->getRigidBody()->setVelocity(Vec2(10, 100));

				pot->setCurrentScene(_enemy->getCurrentScene());
				_enemy->getTarget()->getCurrentScene()->addNode(pot);
				_isThrew = true;
			}
		}
		else
		{
			_isThrew = false;
		}
}

void WallEnemyAttackState::onExit()
{
}

EnemyState * WallEnemyAttackState::checkTransition()
{
	if (!_enemy->isTargetInViewRange())
	{
		if (_enemy->getIndex() >= 9)
		{
			return new WallEnemyIdleState(_enemy);
		}
	}
	return nullptr;
}
 
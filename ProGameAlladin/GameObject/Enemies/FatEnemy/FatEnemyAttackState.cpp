#include "FatEnemyAttackState.h"
#include "FatEnemy.h"
#include "FatEnemyWalkState.h"
#include "FatEnemyIdleState.h"
#include "../../Weapons/KnifeToThrow.h"
#include "../../../Framework/Scene.h"

US_NS_JK

FatEnemyAttackState::FatEnemyAttackState()
{
}

FatEnemyAttackState::FatEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("FatEnemy-Attack");
	_enemy->setVelocity(Vec2(0, 0));
}

FatEnemyAttackState::~FatEnemyAttackState()
{
}

void FatEnemyAttackState::onUpdate()
{
	auto fatEnemy = static_cast<FatEnemy*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}
	if (_enemy->getIndex() == 3)
	{
		if (!_isThrew)
		{
			const auto knife = new KnifeToThrow(Vec2(_enemy->getRigidPosition().getX(), _enemy->getRigidPosition().getY()), Size(5, 5));
			if (_enemy->getScale() == Vec2(1, 1))
			{
				knife->getRigidBody()->setVelocity(Vec2(-400, 0));
			}
			else
			{
				knife->getRigidBody()->setVelocity(Vec2(400, 0));
			}

			knife->setCurrentScene(_enemy->getCurrentScene());
			_enemy->getTarget()->getCurrentScene()->addNode(knife);
			_isThrew = true;
		}
	}
	else
	{
		_isThrew = false;
	}
}

void FatEnemyAttackState::onExit()
{

}

EnemyState * FatEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() >= 4)
		{
			return new FatEnemyWalkState(_enemy);
		}
	}
	return nullptr;
}
 
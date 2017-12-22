#include "TransformAttackState.h"
#include "../Jafar.h"
#include "TransformIdleState.h"
#include "TransformBullet.h"
#include "../../../../Framework/Scene.h"
#include "../../../../Framework/GameManager.h"

US_NS_JK

TransformAttackState::TransformAttackState()
{
}

TransformAttackState::TransformAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("Transform-Attack");
	_isThrew = false;
}

TransformAttackState::~TransformAttackState()
{
}

void TransformAttackState::onUpdate()
{
	auto jafar = static_cast<Jafar*>(_enemy);

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
	}

	if (_enemy->getIndex() == 0)
	{
		if (!_isThrew)
		{
			const auto bullet = new TransformBullet(_enemy, Vec2(_enemy->getRigidPosition().getX() + _enemy->getRigidBody()->getSize().getHeight()/2, _enemy->getRigidPosition().getY() + _enemy->getRigidBody()->getSize().getHeight() / 3), Size(90, 23));
			if (_enemy->getScale() == Vec2(1, 1))
			{
				bullet->setScale(Vec2(-0.9, 0.9));
				bullet->getRigidBody()->setVelocity(Vec2(-30, 20));
			}
			else
			{
				bullet->setScale(Vec2(0.9, 0.9));
				bullet->getRigidBody()->setVelocity(Vec2(30, 20));
			}
			bullet->setCurrentScene(_enemy->getCurrentScene());
			_enemy->getTarget()->getCurrentScene()->addNode(bullet);
			_isThrew = true;
		}
	}
	else
	{
		_isThrew = false;
	}
}

void TransformAttackState::onExit()
{
}

EnemyState * TransformAttackState::checkTransition()
{
	if (!_enemy->isTargetInAttackRange())
	{
		return new TransformIdleState(_enemy);
	}

	return nullptr;
}
 
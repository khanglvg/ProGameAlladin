#include "KnifeEnemyIdleState.h"
#include "../../Weapons/KnifeToThrow.h"
#include "KnifeEnemy.h"
#include "../../../Framework/Scene.h"

US_NS_JK

KnifeEnemyIdleState::KnifeEnemyIdleState()
{
}

KnifeEnemyIdleState::KnifeEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("KnifeEnemy-Idle");
	_enemy->setVelocity(Vec2(0, 0));
}

KnifeEnemyIdleState::~KnifeEnemyIdleState()
{
}

void KnifeEnemyIdleState::onUpdate()
{
	if (_enemy->isTargetInViewRange())
	{
		if (_enemy->isRight())
		{
			_enemy->setScale(Vec2(1, 1));
		}
		else
		{
			_enemy->setScale(Vec2(-1, 1));
		}
		int velocityY = -500;
		if (_enemy->isTargetInAttackRange())
		{
			velocityY = -200;
		}
		if (_enemy->getIndex()%4==0)
		{
			if (!_isThrew)
			{
				const auto knife = new KnifeToThrow(Vec2(_enemy->getRigidPosition().getX(), _enemy->getRigidPosition().getY()), Size(5, 5));
				knife->setGravityScale(5.5);
				if (_enemy->getScale() == Vec2(1, 1))
				{
					knife->getRigidBody()->setVelocity(Vec2(400, velocityY));
				}
				else
				{
					knife->getRigidBody()->setVelocity(Vec2(-400, velocityY));
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
}

void KnifeEnemyIdleState::onExit()
{
}

EnemyState * KnifeEnemyIdleState::checkTransition()
{
	return nullptr;
}
 
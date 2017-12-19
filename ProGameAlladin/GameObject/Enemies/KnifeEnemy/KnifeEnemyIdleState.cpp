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
		int velocityY = -350;
		int velocityX = 120;
		if (_enemy->isTargetInAttackRange())
		{
			velocityY = -30;
			velocityX = 300;
		}
		if (_enemy->getIndex() == 9)
		{
			
			if (!_isThrew)
			{				
				if (_expect == 6)
				{
					const auto knife = new KnifeToThrow(_enemy, Vec2(_enemy->getRigidPosition().getX(), _enemy->getRigidPosition().getY()), Size(5, 5));
					knife->setGravityScale(1);
					if (_enemy->getScale() == Vec2(1, 1))
					{
						knife->getRigidBody()->setVelocity(Vec2(velocityX, velocityY));						
					}
					else
					{
						knife->getRigidBody()->setVelocity(Vec2(-velocityX, velocityY));
						knife->getRigidBody()->setPosition(Vec2(_enemy->getRigidPosition().getX() - 30, _enemy->getRigidPosition().getY()));
					}

					knife->setCurrentScene(_enemy->getCurrentScene());
					_enemy->getTarget()->getCurrentScene()->addNode(knife);
					_isThrew = true;
					_expect = 0;
				}
				else
				{
					_expect++;
				}
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
 
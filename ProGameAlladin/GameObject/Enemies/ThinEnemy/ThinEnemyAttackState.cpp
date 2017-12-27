#include "ThinEnemyAttackState.h"
#include "ThinEnemy.h"
#include "ThinEnemyWalkState.h"
#include "ThinEnemyIdleState.h"
#include "ThinEnemyInAttackedState.h"
#include "../../Weapons/Weapon.h"
#include "../../Framework/Scene.h"

US_NS_JK

ThinEnemyAttackState::ThinEnemyAttackState()
{
}

ThinEnemyAttackState::ThinEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("ThinEnemy-Attack");
	_enemy->setVelocity(Vec2(0, 0));

	_weapon = new Weapon(_enemy, _enemy->getRigidPosition(), Size(45, 30), Vec2(30, 12), "thinenemyknife");
	_weapon->setCurrentScene(_enemy->getCurrentScene());
	_weapon->getRigidBody()->setActive(true);

	_enemy->getCurrentScene()->addNode(_weapon);

}

ThinEnemyAttackState::~ThinEnemyAttackState()
{
}

void ThinEnemyAttackState::onUpdate()
{
	auto thinEnemy = static_cast<ThinEnemy*>(_enemy);


	//const auto distance = (_enemy->getRect().getWidth() - _weapon->getSize().getWidth()) / 2;

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

	if(_enemy->getIndex() == 2 || _enemy->getIndex() == 3)
	{
		_weapon->getRigidBody()->setActive(true);
	}
	else
	{
		_weapon->getRigidBody()->setActive(false);
	}

}

void ThinEnemyAttackState::onExit()
{
	_weapon->getRigidBody()->setActive(false);
	_enemy->getCurrentScene()->removeNode(_weapon);
}

EnemyState * ThinEnemyAttackState::checkTransition()
{
	if (_enemy->isTargetInViewRange() && !_enemy->isTargetInAttackRange())
	{
		if (_enemy->getIndex() == 0)
		{
			return new ThinEnemyWalkState(_enemy);
		}
	}

	if (_enemy->getIsCollisionWithAladdin())
	{
		return new ThinEnemyInAttackedState(_enemy);
	}
	return nullptr;
}

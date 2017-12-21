#include "JafarAttackState.h"
#include "Jafar.h"
#include "JafarIdleState.h"
#include "JafarBullet.h"
#include "../../../Framework/Scene.h"
#include "../../../Framework/GameManager.h"

US_NS_JK

JafarAttackState::JafarAttackState()
{
}

JafarAttackState::JafarAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	_enemy = enemy;
	_enemy->setActionName("Attack");
	_enemy->setVelocity(Vec2(0, 0));
	_bulletNum = 0;
	_delayBullet = 0;
}

JafarAttackState::~JafarAttackState()
{
}

void JafarAttackState::onUpdate()
{
	auto jafar = static_cast<Jafar*>(_enemy);
	auto bulletX = 0;

	if (_enemy->isRight())
	{
		_enemy->setScale(Vec2(-1, 1));
		bulletX = _enemy->getRigidPosition().getX();
	}
	else
	{
		_enemy->setScale(Vec2(1, 1));
		bulletX = _enemy->getRigidPosition().getX() + _enemy->getRigidBody()->getSize().getWidth()/2;
	}

	if (abs(_enemy->getPosition().getX() - _enemy->getTarget()->getPosition().getX()) >= 20)
	{
			if (_delayBullet >= 0.1)
			{
				const auto bullet = new JafarBullet(_enemy, Vec2(bulletX, _enemy->getRigidPosition().getY() - _enemy->getRigidBody()->getSize().getHeight()), Size(30, 15), _enemy->getTarget());
				bullet->setCurrentScene(_enemy->getCurrentScene());
				_enemy->getTarget()->getCurrentScene()->addNode(bullet);
				_bulletNum++;
				_delayBullet = 0;
			}
			else
			{
				_delayBullet += GameManager::getInstance()->getDeltaTime();
			}
	}
}

void JafarAttackState::onExit()
{
}

EnemyState * JafarAttackState::checkTransition()
{
	if (!_enemy->isTargetInAttackRange())
	{
		return new JafarIdleState(_enemy);
	}

	if (abs(_enemy->getPosition().getX() - _enemy->getTarget()->getPosition().getX()) < 20)
	{
		return new JafarIdleState(_enemy);
	}

	if (_bulletNum > 30)
	{
		return new JafarIdleState(_enemy);
	}

	return nullptr;
}
 
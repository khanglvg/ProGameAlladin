#include "JafarIdleState.h"
#include "JafarAttackState.h"
#include "Jafar.h"
#include "../../../Framework/GameManager.h"

US_NS_JK

JafarIdleState::JafarIdleState()
{
}

JafarIdleState::JafarIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	_enemy = enemy;
	_enemy->setActionName("Idle");
	_enemy->setVelocity(Vec2(0, 0));
	_delay = 0;
}

JafarIdleState::~JafarIdleState()
{
}

void JafarIdleState::onUpdate()
{
	auto jafar = static_cast<Jafar*>(_enemy);
}

void JafarIdleState::onExit()
{
}

EnemyState * JafarIdleState::checkTransition()
{
	if (abs(_enemy->getPosition().getX() - _enemy->getTarget()->getPosition().getX()) < 40)
	{
		return nullptr;
	}
	if (_enemy->isTargetInAttackRange() && _delay >= 1)
	{
		return new JafarAttackState(_enemy);
	}
	else
	{
		_delay += GameManager::getInstance()->getDeltaTime();
	}

	return nullptr;
}

 
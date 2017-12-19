#include "FloatGroundNormalState.h"
#include "../../../Framework/GameManager.h"
#include "FloatGroundFallingState.h"

US_NS_JK

FloatGroundNormalState::FloatGroundNormalState()
{
}

FloatGroundNormalState::FloatGroundNormalState(FloatGround * floatground) : FloatGroundState(floatground, FloatGroundState::Normal)
{
	_floatGround = floatground;
	_floatGround->setVelocity(Vec2(0,0));
	_floatGround->setActionName("FloatGround-Normal");
}

FloatGroundNormalState::~FloatGroundNormalState()
{
}

void FloatGroundNormalState::onUpdate()
{
	if (_floatGround->isOnCollision())
	{
		_check = true;
	}
	if (_index <= 0.2 && _check)
	{
		_index += GameManager::getInstance()->getDeltaTime();
	}
}

void FloatGroundNormalState::onExit()
{
}

FloatGroundState * FloatGroundNormalState::checkTransition()
{
	if (_index > 0.2)
	{
		_floatGround->getRigidBody()->setActive(false);
		return new FloatGroundFallingState(_floatGround);
	}

	return nullptr;
}
 
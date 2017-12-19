#include "FloatGroundFallingState.h"
#include "FloatGroundNormalState.h"
#include "../../../Framework/Scene.h"

US_NS_JK

FloatGroundFallingState::FloatGroundFallingState()
{
}

FloatGroundFallingState::FloatGroundFallingState(FloatGround * floatground) : FloatGroundState(floatground, FloatGroundState::StateName::Normal)
{
	_floatGround = floatground;
	_floatGround->setVelocity(Vec2(0,200));
	_floatGround->setActionName("FloatGround-Falling");
}

FloatGroundFallingState::~FloatGroundFallingState()
{
}

void FloatGroundFallingState::onUpdate()
{
}

void FloatGroundFallingState::onExit()
{
}

FloatGroundState * FloatGroundFallingState::checkTransition()
{
	if (_floatGround->getIndex() == 7)
	{
		_floatGround->setVisible(false);
		return new FloatGroundNormalState(_floatGround);
	}

	return nullptr;
}
 
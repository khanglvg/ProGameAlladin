#include "FloatGroundNormalState.h"

US_NS_JK

FloatGroundNormalState::FloatGroundNormalState()
{
}

FloatGroundNormalState::FloatGroundNormalState(FloatGround * springBoard) : FloatGroundState(springBoard, FloatGroundState::Normal)
{
	auto _floatground = static_cast<FloatGround*>(springBoard);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	_floatground->setActionName("SpringBoard-Idle");
}

FloatGroundNormalState::~FloatGroundNormalState()
{
}

void FloatGroundNormalState::onExit()
{
}

FloatGroundState * FloatGroundNormalState::checkTransition()
{
	return nullptr;
}
 
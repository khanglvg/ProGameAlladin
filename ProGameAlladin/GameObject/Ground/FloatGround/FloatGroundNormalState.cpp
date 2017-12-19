#include "SpringBoardIdleState.h"

US_NS_JK

SpringBoardIdleState::SpringBoardIdleState()
{
}

SpringBoardIdleState::SpringBoardIdleState(SpringBoard * springBoard) : SpringBoardState(springBoard, SpringBoardState::StateName::Idle)
{
	auto _springboard = static_cast<SpringBoard*>(springBoard);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	_springboard->setActionName("SpringBoard-Idle");
}

SpringBoardIdleState::~SpringBoardIdleState()
{
}

void SpringBoardIdleState::onExit()
{
}

SpringBoardState * SpringBoardIdleState::checkTransition()
{
	return nullptr;
}
 
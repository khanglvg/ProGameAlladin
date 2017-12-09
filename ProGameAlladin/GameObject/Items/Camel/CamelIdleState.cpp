#include "CamelIdleState.h"

US_NS_JK

CamelIdleState::CamelIdleState()
{
}

CamelIdleState::CamelIdleState(Camel * camel) : CamelState(camel, CamelState::StateName::Idle)
{
	auto _camel = static_cast<Camel*>(camel);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	_camel->setActionName("Camel-Idle");
}

CamelIdleState::~CamelIdleState()
{
}

void CamelIdleState::onExit()
{
}

CamelState * CamelIdleState::checkTransition()
{
	return nullptr;
}
 
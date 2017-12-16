#include "JumpAndSlash.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "../GameObject/Aladdin.h"
#include "Grounding.h"
US_NS_JK

JumpAndSlash::JumpAndSlash(Node* node):State(node)
{
}

JumpAndSlash::~JumpAndSlash()
{
}

void JumpAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	const auto aladdin = static_cast<Aladdin*>(_node);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));*/

	aladdin->setActionName("JumpAndSlash");
}

void JumpAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
	}
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
	}

	//if (Input::getInstance()->getKey(KEY_D) && _state == NONE)
	//{
	//	_state = JUMP;
	//}
	//if (_state == JUMP)
	//{
	//	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	//		aladdin->setVelocity(Vec2(aladdin->getVelocity().getX()-2, aladdin->getVelocity().getY()));
	//	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	//		aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2, aladdin->getPosition().getY() - 2));
	//	if (aladdin->getPosition().getY() < aladdin->getMaxHeight())
	//		_state = FALL;
	//}
	//if (_state == FALL)
	//{
	//	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	//		aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2, aladdin->getPosition().getY() + 2));
	//	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	//		aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2, aladdin->getPosition().getY() + 2));
	//	if (aladdin->getPosition().getY() >= aladdin->getYGround())
	//		_state = NONE;
	//}
}

void JumpAndSlash::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setVelocity(Vec2(0, 0));
}

State* JumpAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);


	if (aladdin->isOnTheGround())
		return new Grounding(_node);
	
	if (aladdin->isBesideTheStair())
		return new Idle(_node);

	return nullptr;
}



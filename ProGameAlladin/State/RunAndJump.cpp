#include "RunAndJump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "Run.h"
#include "Fall.h"
#include "IdleToClimb.h"
US_NS_JK

RunAndJump::RunAndJump(Node* node):State(node)
{
}

RunAndJump::~RunAndJump()
{
}

void RunAndJump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-150, -270));
	}
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(150, -270));
	}

	aladdin->getRigidBody()->setSize(Size(4, 60));
	aladdin->setActionName("RunAndJump");
}

void RunAndJump::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (Input::getInstance()->getKey(KEY_D) && _state == NONE)
	{
		_state = JUMP;
	}
	if (_state == FALL)
	{
	}
	if(aladdin->isOnTheGround()== false)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(-150, aladdin->getVelocity().getY()));
		}
		
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(150, aladdin->getVelocity().getY()));
		}
			
	}
}

void RunAndJump::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->getRigidBody()->setSize(Size(10, 60));
}

State* RunAndJump::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (_state == NONE && Input::getInstance()->isAnyKeyDown())
		return new Idle(_node);
	if (_state == NONE && Input::getInstance()->isKeyDown(KEY_LEFT_ARROW))
		return new Run(_node);
	if (_state == NONE && Input::getInstance()->isKeyDown(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (!Input::getInstance()->getKey(KEY_D))
		_state = FALL;
	if (aladdin->isOnTheGround() || aladdin->isBesideTheStair() || aladdin->isOnTheFire())// || aladdin->isOnThePlatform())
		return new Idle(_node);
	if (aladdin->isOnTheRope())
	{
		return new IdleToClimb(_node);
	}
	return nullptr;
}

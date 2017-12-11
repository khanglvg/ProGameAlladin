#include "RunAndJump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "Run.h"
#include "Fall.h"
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
		aladdin->setVelocity(Vec2(-200, -300));
	}
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(200, -300));
	}

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
	if(aladdin->getisOnTheGround()== false)
	{
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
			
	}
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
	if (aladdin->getisOnTheGround())
		return new Idle(_node);

	return nullptr;
}

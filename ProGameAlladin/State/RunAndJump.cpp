#include "RunAndJump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../Aladdin.h"
#include "Run.h"
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
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

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
	if (_state == JUMP)
	{
		if(Input::getInstance()->getKey(KEY_LEFT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2 , aladdin->getPosition().getY() - 2));
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2, aladdin->getPosition().getY() - 2));
		if (aladdin->getPosition().getY() < aladdin->getMaxHeight())
			_state = FALL;
	}
	if (_state == FALL)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2, aladdin->getPosition().getY() + 2));
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2, aladdin->getPosition().getY() + 2));
		if (aladdin->getPosition().getY() >= aladdin->getYGround())
			_state = NONE;
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
	if (_state == NONE && Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (_state == NONE && Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (!Input::getInstance()->getKey(KEY_D))
		_state = FALL;
	

	return nullptr;
}

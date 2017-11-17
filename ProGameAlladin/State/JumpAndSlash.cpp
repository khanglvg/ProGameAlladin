#include "JumpAndSlash.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "../Aladdin.h"
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

	aladdin->setActionName("JumpAndSlash");
}

void JumpAndSlash::onUpdate()
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
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2, aladdin->getPosition().getY() - 2));
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

State* JumpAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);

	if (_state == NONE)
		return new Idle(_node);

	if (aladdin->getIndex() >= 5)
		return new Idle(_node);

	return nullptr;
}



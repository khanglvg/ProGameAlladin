#include "Jump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../Aladdin.h"
#include "Run.h"
#include "Sit.h"
US_NS_JK

Jump::Jump(Node* node):State(node)
{
}

Jump::~Jump()
{
}

void Jump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	
	aladdin->setActionName("Jump");
}

void Jump::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D) && _state == NONE)
	{
		_state = JUMP;
	}
	if (_state == JUMP)
	{
		aladdin->setPosition(Vec2(aladdin->getPosition().getX(), aladdin->getPosition().getY() - 2));
		if (aladdin->getPosition().getY() < aladdin->getMaxHeight())
			_state = FALL;
	}
	if(_state == FALL)
	{
		aladdin->setPosition(Vec2(aladdin->getPosition().getX(), aladdin->getPosition().getY() + 2));
		if (aladdin->getPosition().getY() >= aladdin->getYGround())
			_state = NONE;
	}
}

State* Jump::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->isAnyKeyDown())
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	
	if (Input::getInstance()->getKey(KEY_D)){}
	// ??

	if (_state == NONE)
		return new Idle(_node);

	return nullptr;
}

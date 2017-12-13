#include "RunAndSlash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "RunAndJump.h"
#include "../GameObject/Aladdin.h"
#include "HeadUp.h"
#include "Sit.h"
#include "Run.h"
#include "Slash.h"
US_NS_JK

RunAndSlash::RunAndSlash(Node* node):State(node)
{
}

RunAndSlash::~RunAndSlash()
{
}

void RunAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);


	aladdin->setActionName("RunAndSlash");
}

void RunAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));
	//if(Input::getInstance()->getKey(KEY_S)&& _state==NONE)
	{
		_state = RUN;
	}
	/*if (_state == RUN)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2,aladdin->getPosition().getY()));
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2,aladdin->getPosition().getY()));
	}*/
}

State* RunAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (Input::getInstance()->isKeyUp(KEY_S))
		return new Run(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);

	//if (aladdin->getIndex() >= 5)
	//{ 
	//	return new Idle(_node);
	//}


	return nullptr;
}

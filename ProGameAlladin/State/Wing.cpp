#include "Wing.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "SlashWhenWing.h"
#include "ThrowWhenWing.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

Wing::Wing(Node* node):State(node)
{
}

Wing::~Wing()
{
}

void Wing::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("Wing");
}

void Wing::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);


	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		if (aladdin->isAllowToClimb())
		{
			aladdin->setIsPause(false);
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(-100, 0));
		}
		else
		{
			aladdin->setIsPause(true);
			aladdin->setVelocity(Vec2(0, 0));
		}
	}
	else if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setIsPause(false);
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(100,0));
	}
	else
	{
		aladdin->setIsPause(true);
	}



	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW) || Input::getInstance()->isKeyUp(KEY_DOWN_ARROW))
	{
		aladdin->setVelocity(Vec2(0, 0));
	}
}

void Wing::onExit()
{

}

State* Wing::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_D))
	{
		
	}
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenWing(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new ThrowWhenWing(_node);

	return nullptr;
}

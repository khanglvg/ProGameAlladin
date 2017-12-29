#include "Wing.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "IdleWhenWing.h"
#include "../GameObject/Aladdin.h"
#include "Fall.h"

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

	aladdin->setActionName("Wing");
}

void Wing::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);


	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		if (aladdin->getScale() == Vec2(-1,1))
		{
			aladdin->setScale(Vec2(1, 1));
		}
		aladdin->setVelocity(Vec2(-100, 0));
	}
	else if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		if (aladdin->getScale() == Vec2(1, 1))
		{
			aladdin->setScale(Vec2(-1, 1));
		}
		aladdin->setVelocity(Vec2(100,0));
	}
}

void Wing::onExit()
{

}

State* Wing::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
	{
		return new IdleWhenWing(aladdin);
	}

	if (aladdin->isBesideTheWall())
	{
		aladdin->getRigidBody()->setActive(false);
		aladdin->setIsWing(false);
		return new Fall(_node);
	}

	return nullptr;
}

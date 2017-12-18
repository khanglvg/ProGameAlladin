#include "Fall.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "IdleToClimb.h"
US_NS_JK

Fall::Fall(Node* node):State(node)
{
}

Fall::~Fall()
{
}

void Fall::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Fall");
}

void Fall::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	//if (!aladdin->isOnTheRope())
	{
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
		}
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
		}
		aladdin->getRigidBody()->setGravityScale(1);
	}
}

State* Fall::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (aladdin->isOnTheRope())
		return new IdleToClimb(_node);
	if (aladdin->isOnTheGround())
		return new Idle(_node);
	return nullptr;
}

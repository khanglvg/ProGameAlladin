#include "Fall.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "IdleToClimb.h"
#include "Grounding.h"
#include "IdleWhenWing.h"
#include "../Framework/GameManager.h"
#include "Flip.h"
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
	aladdin->getRigidBody()->setGravityScale(2.7);
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
		
	}

	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW)||Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
	{
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}


	if (_expect >= 0.1)
	{
		aladdin->getRigidBody()->setActive(true);
	}
	else
	{
		_expect += GameManager::getInstance()->getDeltaTime();
	}

}

void Fall::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setVelocity(Vec2(0, 0));
	aladdin->getRigidBody()->setGravityScale(1.5);
}

State* Fall::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new JumpAndThrow(_node);

	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	if (aladdin->isOnTheRope())
		return new IdleToClimb(_node);

	if (aladdin->isOnTheGround() || aladdin->isOnThePlatform() || aladdin->isOnTheFire())
		return new Grounding(_node);

	if (aladdin->getIndex() >= 8)
		aladdin->setIsPause(true);

	if (aladdin->isInSpringBoard())
		return new Flip(_node);

	if (aladdin->isWing() && aladdin->getVelocity().getY() > 0)
	{
		return new IdleWhenWing(_node);
	}
	return nullptr;
}

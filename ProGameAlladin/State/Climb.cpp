#include "Climb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "../GameObject/Aladdin.h"
#include "SlashWhenClimb.h"
#include "ThrowWhenClimb.h"
#include "IdleToClimb.h"
US_NS_JK

Climb::Climb(Node* node):State(node)
{
}

Climb::~Climb()
{
}

void Climb::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	
	
	//aladdin->setVelocity(Vec2(0, 0));
	aladdin->setActionName("Climb");
	
}

void Climb::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);


	if (Input::getInstance()->getKey(KEY_UP_ARROW))
	{
		if (aladdin->isAllowToClimb())
		{
			aladdin->setIsPause(false);
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(0, -100));
		}
		else
		{
			aladdin->setIsPause(true);
			aladdin->setVelocity(Vec2(0, 0));
		}
	}
	else if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		{
			aladdin->setIsClimbDown(true);
			aladdin->setIsPause(false);
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(0, 100));
		}
		else
		{
			aladdin->setIsClimbDown(false);
			aladdin->setIsPause(true);
		}

	

	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW) || Input::getInstance()->isKeyUp(KEY_DOWN_ARROW))
	{
		aladdin->setVelocity(Vec2(0, 0));
	}

	if(Input::getInstance()->getKey(KEY_D)&&Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->getRigidBody()->setGravityScale(1);
		aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
	}
	if (Input::getInstance()->getKey(KEY_D) && Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->getRigidBody()->setGravityScale(1);
		aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
	}
}

State* Climb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->isKeyDown(KEY_S))
		return new SlashWhenClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);
	if (!aladdin->isOnTheRope())
	{
		aladdin->getRigidBody()->setGravityScale(1);
		return new Idle(_node);
	}
		
	return nullptr;
}

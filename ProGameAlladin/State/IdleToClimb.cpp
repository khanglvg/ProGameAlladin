#include "IdleToClimb.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "Climb.h"
#include "SlashWhenClimb.h"
#include "JumpWhileClimb.h"
#include "ThrowWhenClimb.h"
US_NS_JK

IdleToClimb::IdleToClimb(Node* node):State(node)
{
}

IdleToClimb::~IdleToClimb()
{
}

void IdleToClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("IdleToClimb");

	aladdin->getRigidBody()->setGravityScale(0);
	aladdin->setVelocity(Vec2(0, 0));

}

void IdleToClimb::onUpdate()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setIsOwnerRight(false);
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(0, 0));
		}

		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setIsOwnerRight(true);
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(0, 0));
		}
	
		
	
	if (Input::getInstance()->getKey(KEY_D) && Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->getRigidBody()->setGravityScale(1);
		aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
		aladdin->getRigidBody()->setActive(false);
		aladdin->setIsClimb(false);
	}
	if (Input::getInstance()->getKey(KEY_D) && Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->getRigidBody()->setGravityScale(1);
		aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
		aladdin->getRigidBody()->setActive(false);
		aladdin->setIsClimb(false);
	}




}

void IdleToClimb::onExit()
{

}


State* IdleToClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->isKeyDown(KEY_S))
		return new SlashWhenClimb(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new ThrowWhenClimb(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new Climb(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Climb(_node);
	//if (aladdin->isOnTheGround() || aladdin->isOnThePlatform() || aladdin->isOnTheFire())
	//{
	//	return new Idle(_node);
	//}
	/*if (!aladdin->isOnTheRope())
		return new Idle(_node);*/
	return nullptr;
}

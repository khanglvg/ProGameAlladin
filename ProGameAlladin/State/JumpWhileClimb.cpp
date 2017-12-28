#include "JumpWhileClimb.h"
#include "../Framework/Input.h"
#include "JumpAndSlash.h"
#include "JumpAndThrow.h"
#include "Fall.h"
#include "../GameObject/Aladdin.h"
#include "Jump.h"
#include "IdleToClimb.h"
#include "IdleWhenWing.h"

US_NS_JK
JumpWhileClimb::JumpWhileClimb(Node* node):State(node)
{
}

JumpWhileClimb::~JumpWhileClimb()
{
}

void JumpWhileClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setVelocity(Vec2(0, -80));


	aladdin->setActionName("JumpWhileClimb");
}

void JumpWhileClimb::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	{
		{

			if (Input::getInstance()->getKey(KEY_D) && Input::getInstance()->getKey(KEY_LEFT_ARROW))
			{
				aladdin->getRigidBody()->setGravityScale(1);
				aladdin->setVelocity(Vec2(-90, -120));
			}
			if (Input::getInstance()->getKey(KEY_D) && Input::getInstance()->getKey(KEY_RIGHT_ARROW))
			{
				aladdin->getRigidBody()->setGravityScale(1);
				aladdin->setVelocity(Vec2(80, -120));
			}
		}



		//if (!aladdin->isOnTheRope())
		//{
		//		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		//	{
		//	aladdin->setVelocity(Vec2(50, aladdin->getVelocity().getY()));
		//	}
		//	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		//	{
		//	aladdin->setVelocity(Vec2(-50, aladdin->getVelocity().getY()));
		//	}
		//	aladdin->getRigidBody()->setGravityScale(2);
		//}
	}
}

void JumpWhileClimb::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->getRigidBody()->setGravityScale(1.5);
}

State* JumpWhileClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (aladdin->isOnTheRope())
	{
		if (aladdin->getIndex() >= 3)
		{	
			return new IdleToClimb(_node);
		}
	}
	if (aladdin->isOnTheGround())
		return new Idle(_node);

	if(!aladdin->isOnTheRope())
	{
		if(aladdin->getIndex()>=6)
		{
			return new Fall(_node);
		}
		
	}

	if(aladdin->isOnTheHorizontalBar())
	{
		return new IdleWhenWing(_node);
	}


	return nullptr;
}

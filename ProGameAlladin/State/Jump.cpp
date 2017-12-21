#include "Jump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "Run.h"
#include "IdleToSit.h"
#include "Climb.h"
#include "IdleToClimb.h"
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

	aladdin->setVelocity(Vec2(0, -250)); // -300 is High jump (hold D), -200 is a normal jump
	aladdin->getRigidBody()->setSize(Size(4, 30));
	aladdin->setActionName("Jump");
}

void Jump::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
		
	}

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
	}
}

void Jump::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->getRigidBody()->setSize(Size(10, 30));
}

State* Jump::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);



	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	if (aladdin->isOnTheGround() || aladdin->isBesideTheStair() || aladdin->isOnThePlatform() || aladdin->isOnTheFire())
		return new Idle(_node);


	if (aladdin->isOnTheRope())
	{
		aladdin->setRigidPosition(Vec2(aladdin->getRigidPosition().getX() + aladdin->getRigidBody()->getSize().getWidth() / 2, aladdin->getRigidPosition().getY()));
		aladdin->setPosition(aladdin->getRigidPosition() - aladdin->getRigidBody()->getOffset());
		return new IdleToClimb(_node);
	}

	//if (aladdin->isOnTheGround() && (Input::getInstance()->isKeyDown(KEY_D)))
	//{
	//	return new Idle(_node);
	//}
	
	

	

	return nullptr;
}

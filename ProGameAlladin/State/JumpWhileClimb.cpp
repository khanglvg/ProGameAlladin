#include "JumpWhileClimb.h"
#include "../Framework/Input.h"
#include "JumpAndSlash.h"
#include "JumpAndThrow.h"
#include "Fall.h"
#include "../GameObject/Aladdin.h"
#include "Jump.h"
#include "IdleToClimb.h"

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

	aladdin->setVelocity(Vec2(0, -150));

	aladdin->setActionName("JumpWhileClimb");
}

State* JumpWhileClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (aladdin->getIndex() >= 8)
	{
		aladdin->setVelocity(Vec2(0, 0));
		return new IdleToClimb(_node);
	}
		
	if(!aladdin->isOnTheRope())
	{
		aladdin->getRigidBody()->setGravityScale(1);
		return new Jump(_node);
	}
	//if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	//	return new Jump(_node);
	//if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	//	return new Jump(_node);


	return nullptr;
}

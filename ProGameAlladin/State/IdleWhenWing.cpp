#include "IdleWhenWing.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "Fall.h"
#include "Wing.h"
#include "SlashWhenWing.h"
#include "ThrowWhenWing.h"
US_NS_JK

IdleWhenWing::IdleWhenWing(Node* node):State(node)
{
}

IdleWhenWing::~IdleWhenWing()
{
}

void IdleWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("IdleWhenClimbing");
	aladdin->getRigidBody()->setGravityScale(0);
	aladdin->getRigidBody()->setVelocity(Vec2(0,0));
}

State* IdleWhenWing::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_D))
	{
		aladdin->getRigidBody()->setActive(false);
		aladdin->setIsWing(false);
		return new Fall(_node);
	}

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW) || Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		return new Wing(_node);
	}

	if (Input::getInstance()->getKey(KEY_S))
	{
		return new SlashWhenWing(_node);
	}

	if (Input::getInstance()->getKey(KEY_A))
	{
		return new ThrowWhenWing(_node);
	}
	return nullptr;
}

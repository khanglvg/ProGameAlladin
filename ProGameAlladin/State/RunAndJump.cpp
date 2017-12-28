#include "RunAndJump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "Run.h"
#include "Fall.h"
#include "IdleToClimb.h"
#include "Jump.h"
#include "../Framework/Audio.h"
#include "../Lv1Scene.h"
#include "Flip.h"
US_NS_JK

RunAndJump::RunAndJump(Node* node):State(node)
{
}

RunAndJump::~RunAndJump()
{
}

void RunAndJump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	
	auto aladdin = static_cast<Aladdin*>(_node);
	auto scale = 1;


	if(aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(-140*scale, -290 * scale));
			aladdin->getRigidBody()->setSize(Size(15, 30));
		}
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(140 * scale, -290 * scale));
			aladdin->getRigidBody()->setSize(Size(15, 30));
		}
	}
	else
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(-180, -310));
			aladdin->getRigidBody()->setSize(Size(10, 60));
		}
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(180, -310));
			aladdin->getRigidBody()->setSize(Size(10, 60));
		}
	}
	
	aladdin->setActionName("RunAndJump");
}

void RunAndJump::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (Input::getInstance()->getKey(KEY_D) && _state == NONE)
	{
		_state = JUMP;
	}
	if (_state == FALL)
	{
	}
	if(aladdin->isOnTheGround()== false)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		{
			aladdin->setScale(Vec2(-1, 1));
			aladdin->setVelocity(Vec2(-150, aladdin->getVelocity().getY()));
		}
		
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		{
			aladdin->setScale(Vec2(1, 1));
			aladdin->setVelocity(Vec2(150, aladdin->getVelocity().getY()));
		}
			
	}

	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
	{
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}
}

void RunAndJump::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
		aladdin->getRigidBody()->setSize(Size(15, 30));
	else
		aladdin->getRigidBody()->setSize(Size(10, 60));
}

State* RunAndJump::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple()>0)
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (_state == NONE && Input::getInstance()->isAnyKeyDown())
		return new Idle(_node);
	if (_state == NONE && Input::getInstance()->isKeyDown(KEY_LEFT_ARROW))
		return new Run(_node);
	if (_state == NONE && Input::getInstance()->isKeyDown(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (!Input::getInstance()->getKey(KEY_D))
		_state = FALL;
	if (aladdin->isOnTheGround() || aladdin->isBesideTheStair() || aladdin->isOnTheFire() || aladdin->isOnThePlatform())
		return new Idle(_node);
	if (aladdin->isClimb())
		return new IdleToClimb(_node);
	if (aladdin->isInCamel())
	{
		auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
		Audio::get()->play(lv1->getsoundCamel(), false);
		return new Jump(_node);
	}
		
	if (aladdin->getIndex() >= 6)
		aladdin->setIsPause(true);

	if (aladdin->isInSpringBoard())
		return new Flip(_node);
	return nullptr;
}

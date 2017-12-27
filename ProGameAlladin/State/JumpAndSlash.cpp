#include "JumpAndSlash.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "../GameObject/Aladdin.h"
#include "Grounding.h"
#include "IdleToClimb.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"
#include "../BossScene.h"
US_NS_JK

JumpAndSlash::JumpAndSlash(Node* node):State(node)
{
}

JumpAndSlash::~JumpAndSlash()
{
}

void JumpAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()

	const auto aladdin = static_cast<Aladdin*>(_node);

	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	auto boss = static_cast<BossScene*>(aladdin->getCurrentScene());

	if (aladdin->getEScene() == Aladdin::ENUM_LV1_SCENE)
	{
		Audio::get()->play(lv1->getsoundSlash(), false);
	}



	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		Audio::get()->play(boss->getsoundSlash(), false);
	}
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));*/

	aladdin->setActionName("JumpAndSlash");

	_weapon = new Weapon(aladdin, aladdin->getRigidPosition(), Size(25, 30), Vec2(22, 12), "aladdinknife");

	if (aladdin->isOwnerRight())
	{
		_weapon->getOwner()->setIsOwnerRight(true);
		_weapon->getRigidBody()->setActive(true);
	}
	else
	{
		_weapon->getOwner()->setIsOwnerRight(false);
		_weapon->getRigidBody()->setActive(true);
	}

	_weapon->setCurrentScene(aladdin->getCurrentScene());
	aladdin->getCurrentScene()->addNode(_weapon);
}

void JumpAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-100, aladdin->getVelocity().getY()));
		_weapon->getOwner()->setIsOwnerRight(false);
	}
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(100, aladdin->getVelocity().getY()));
		_weapon->getOwner()->setIsOwnerRight(true);
	}

	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
	{
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}
}

void JumpAndSlash::onExit()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setVelocity(Vec2(0, 0));
	_weapon->getRigidBody()->setActive(false);
	aladdin->getCurrentScene()->removeNode(_weapon);
}

State* JumpAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new JumpAndThrow(_node);

	if (aladdin->isOnTheGround())
		return new Idle(_node);
	
	if (aladdin->isBesideTheStair())
		return new Idle(_node);

	if (aladdin->isOnThePlatform())
		return new Idle(_node);

	if (aladdin->isOnTheRope())
		return new IdleToClimb(_node);

	if (aladdin->getIndex() >= 6)
	{
		aladdin->setIsPause(true);
		if (Input::getInstance()->getKey(KEY_S))
			aladdin->setIsPause(false);
	}
	

	return nullptr;
}



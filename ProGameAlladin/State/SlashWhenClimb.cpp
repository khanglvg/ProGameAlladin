#include "SlashWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "ThrowWhenClimb.h"
#include "../GameObject/Aladdin.h"
#include "IdleToClimb.h"
#include "../Framework/Audio.h"
#include "../Lv1Scene.h"
US_NS_JK

SlashWhenClimb::SlashWhenClimb(Node* node):State(node)
{
}

SlashWhenClimb::~SlashWhenClimb()
{
}

void SlashWhenClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	Audio::get()->play(lv1->getsoundSlash(), false);

	aladdin->setVelocity(Vec2(0, 0));


	aladdin->setActionName("SlashWhenClimbing");

	_weapon = new Weapon(aladdin, aladdin->getRigidPosition(), Size(25, 30), Vec2(22, 25), "aladdinknife");

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

void SlashWhenClimb::onUpdate()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

}

void SlashWhenClimb::onExit()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	_weapon->getRigidBody()->setActive(false);
	aladdin->getCurrentScene()->removeNode(_weapon);
}

State* SlashWhenClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new ThrowWhenClimb(_node);
	if (aladdin->getIndex() >= 6)
		return new IdleToClimb(_node);
	
	return nullptr;
}

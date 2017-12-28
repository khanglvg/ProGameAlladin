#include "SlashWhenWing.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"

US_NS_JK
SlashWhenWing::SlashWhenWing(Node* node):State(node)
{
}

SlashWhenWing::~SlashWhenWing()
{
}

void SlashWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	Audio::get()->play(lv1->getsoundSlash(), false);

	aladdin->setVelocity(Vec2(0, 0));

	aladdin->setActionName("SlashWhenClimbing");

	_weapon = new Weapon(aladdin, aladdin->getRigidPosition(), Size(25, 30), Vec2(30, 12), "aladdinknife");

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

void SlashWhenWing::onUpdate()
{
}

void SlashWhenWing::onExit()
{
}

State* SlashWhenWing::checkTransition()
{
	return nullptr;
}

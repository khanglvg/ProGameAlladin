#include "SitAndSlash.h"
#include "../Framework/Input.h"
#include "SitAndThrow.h"
#include "Jump.h"
#include "../GameObject/Aladdin.h"
#include "Sit.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"
#include "../BossScene.h"
US_NS_JK

SitAndSlash::SitAndSlash(Node* node):State(node)
{
}

SitAndSlash::~SitAndSlash()
{
}

void SitAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	auto boss = static_cast<BossScene*>(aladdin->getCurrentScene());

	if (aladdin->getEScene() == Aladdin::ENUM_LV1_SCENE)
	{
		Audio::get()->play(lv1->getsoundSitSlash(), false);
	}



	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		Audio::get()->play(boss->getsoundSitSlash(), false);
	}

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-0, aladdin->getVelocity().getY()));
	}

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}

	aladdin->setActionName("SitAndSlash");

	_weapon = new Weapon(aladdin, aladdin->getRigidPosition(), Size(15, 20), Vec2(55, -5), "aladdinknife");

	if (aladdin->isOwnerRight())
	{
		_weapon->getRigidBody()->setActive(true);
	}
	else
	{
		_weapon->getRigidBody()->setActive(true);
	}

	_weapon->setCurrentScene(aladdin->getCurrentScene());
	aladdin->getCurrentScene()->addNode(_weapon);
}

void SitAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));
}

void SitAndSlash::onExit()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	_weapon->getRigidBody()->setActive(false);
	aladdin->getCurrentScene()->removeNode(_weapon);
}

State* SitAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new SitAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (!Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Idle(_node);
	if (aladdin->getIndex() >= 6)
		return new Sit(_node);

		return nullptr;
}

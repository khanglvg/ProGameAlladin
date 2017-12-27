#include "RunAndSlash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "RunAndJump.h"
#include "../GameObject/Aladdin.h"
#include "HeadUp.h"
#include "Sit.h"
#include "Run.h"
#include "Slash.h"
#include "../Framework/Audio.h"
#include "../BossScene.h"
#include "../Lv1Scene.h"
US_NS_JK

RunAndSlash::RunAndSlash(Node* node):State(node)
{
}

RunAndSlash::~RunAndSlash()
{
}

void RunAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

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

	aladdin->setActionName("RunAndSlash");

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

void RunAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));
	//if(Input::getInstance()->getKey(KEY_S)&& _state==NONE)
	{
		_state = RUN;
	}
	/*if (_state == RUN)
	{
		if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() - 2,aladdin->getPosition().getY()));
		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
			aladdin->setPosition(Vec2(aladdin->getPosition().getX() + 2,aladdin->getPosition().getY()));
	}*/
}

void RunAndSlash::onExit()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	_weapon->getRigidBody()->setActive(false);
	aladdin->getCurrentScene()->removeNode(_weapon);
}

State* RunAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (Input::getInstance()->isKeyUp(KEY_S))
		return new Run(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);

	if (aladdin->getIndex() >= 5 &&Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{ 
		return new Run(_node);
	}


	return nullptr;
}

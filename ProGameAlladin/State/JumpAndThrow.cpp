#include "JumpAndThrow.h"
#include "../Framework/Input.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
#include "../GameObject/Weapons/AppleToThrow.h"
#include "../Framework/Scene.h"
#include "IdleToClimb.h"
#include "../Framework/Audio.h"
#include "../Lv1Scene.h"
#include "../BossScene.h"
US_NS_JK

JumpAndThrow::JumpAndThrow(Node* node):State(node)
{
}

JumpAndThrow::~JumpAndThrow()
{
}

void JumpAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	//if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	//	aladdin->setScale(Vec2(-1, 1));

	//if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	//	aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("JumpAndThrow");
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	auto boss = static_cast<BossScene*>(aladdin->getCurrentScene());

	if (aladdin->getEScene() == Aladdin::ENUM_LV1_SCENE)
	{
		Audio::get()->play(lv1->getsoundThrowing(), false);
	}



	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		Audio::get()->play(boss->getsoundThrowing(), false);
	}

	{
		const auto apple = new AppleToThrow(aladdin, Vec2(aladdin->getRigidPosition().getX(), aladdin->getRigidPosition().getY() - 20), Size(5, 5));
		if (aladdin->getScale() == Vec2(1, 1))
		{
			apple->getRigidBody()->setVelocity(Vec2(450, 0));
		}
		else
		{
			apple->getRigidBody()->setVelocity(Vec2(-450, 0));
		}

		apple->setCurrentScene(aladdin->getCurrentScene());
		aladdin->getCurrentScene()->addNode(apple);
		aladdin->desApple();
	}
}

void JumpAndThrow::onUpdate()
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

State* JumpAndThrow::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	
	if (aladdin->isOnTheGround())
		return new Idle(_node);

	if (aladdin->isOnTheRope())
		return new IdleToClimb(_node);

	if (aladdin->getIndex() >= 4)
		return new Idle(_node);

	return nullptr;
}

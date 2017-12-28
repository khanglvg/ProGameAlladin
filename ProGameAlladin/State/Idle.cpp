#include "Idle.h"
#include "Run.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "HeadUp.h"
#include "IdleToSit.h"
#include "Slash.h"
#include "Throw.h"
#include "../GameObject/Aladdin.h"
#include "../Lv1Scene.h"
#include <iostream>
#include "Random.h"
#include "Idle2.h"
#include "Idle3.h"
#include "BeingAttacked.h"
#include "../Framework/Audio.h"



US_NS_JK


Idle::Idle(Node* node) :State(node)
{
}

Idle::~Idle()
{
}


void Idle::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));*/
	aladdin->setActionName("Idle1");

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
		aladdin->getRigidBody()->setSize(Size(15, 30));

	aladdin->setVelocity(Vec2(0, 0));
	aladdin->getRigidBody()->setGravityScale(1.5);

}

void Idle::onUpdate()
{



}

State* Idle::checkTransition()
{
	auto const aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{

		return new Run(_node);

	}

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->isKeyDown(KEY_D))
	{
	
		return new Jump(_node);
	}

	if (Input::getInstance()->getKey(KEY_UP_ARROW) && aladdin->isOnTheGround())
	{
		return new HeadUp(_node);
	}

	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_S))
	{
	
		return new Slash(_node);
	}
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);

	if (aladdin->isAttacked())
		return new BeingAttacked(_node);

	return nullptr;

}

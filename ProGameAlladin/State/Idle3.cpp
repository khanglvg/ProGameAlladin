﻿#include "Idle3.h"
#include "../GameObject/Aladdin.h"
#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "IdleToSit.h"
#include "HeadUp.h"
#include "Jump.h"
#include "Run.h"
#include "BeingAttacked.h"
#include "Flip.h"

US_NS_JK
Idle3::Idle3(Node* node):State(node)
{
}

Idle3::~Idle3()
{
}

void Idle3::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Idle3");
	aladdin->setVelocity(Vec2(0, 0));

	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
		aladdin->getRigidBody()->setSize(Size(15, 30));

}

State* Idle3::checkTransition()
{
	auto const aladdin = static_cast<Aladdin*>(_node);



	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->isKeyDown(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);
	if (aladdin->isAttacked())
		return new BeingAttacked(_node);
	if (aladdin->isInSpringBoard())
		return new Flip(_node);
	return nullptr;
}

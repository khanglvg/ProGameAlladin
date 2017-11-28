﻿#include "Jump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../Aladdin.h"
#include "Run.h"
#include "IdleToSit.h"
US_NS_JK

Jump::Jump(Node* node):State(node)
{
}

Jump::~Jump()
{
}

void Jump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setVelocity(Vec2(0, -300)); // -300 is High jump (hold D), -200 is a normal jump
	
	aladdin->setActionName("Jump");
}

void Jump::onUpdate()
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

State* Jump::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);



	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	/*if (aladdin->getIndex() >= 8)
		return new Idle(_node);*/
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);*/
	
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);

	if (aladdin->getisOnTheGround())
		return new Idle(_node);
		//tiep dat
	//if (aladdin->getVelocity().getX() == 0 && aladdin->getVelocity().getY() == 0)
	//return new Idle(_node);

	

	return nullptr;
}

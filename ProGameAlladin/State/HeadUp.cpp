#include "HeadUp.h"
#include "State.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "IdleToSit.h"
#include "HeadUpAndSlash.h"
#include "Throw.h"
#include "Idle.h"
#include "../Aladdin.h"
#include "IdleToLook.h"
#include "../Framework/Camera.h"

US_NS_JK

HeadUp::HeadUp(Node* node):State(node)
{
}

HeadUp::~HeadUp()
{
}

void HeadUp::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setActionName("HeadUp"); // Idle to Look -> HeadUp
}

void HeadUp::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(0,0));
	}
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(0, 0));
	}
	if(Input::getInstance()->getKey(KEY_UP_ARROW))
	{
		if(!Camera::getInstance()->isUp())
		{
			Camera::getInstance()->setUp(true);
		}
	}
	if (!Input::getInstance()->getKey(KEY_UP_ARROW))
		Camera::getInstance()->setUp(false);
	
}

void HeadUp::onExit()
{
}

State* HeadUp::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	/*if (Input::getInstance()->getKey(KEY_DOWN_ARROW) && Input::getInstance()->isAnyKeyDown())
		return new Sit(_node);*/
	if (Input::getInstance()->getKey(KEY_S))
		return new HeadUpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW))
		return new Idle(_node);
	/*if (Input::getInstance()->isKeyDown(KEY_UP_ARROW))
		return new IdleToLook(_node);*/

	return nullptr;
}

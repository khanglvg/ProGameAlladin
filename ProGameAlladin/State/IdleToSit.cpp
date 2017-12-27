#include "IdleToSit.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "SitAndSlash.h"
#include "SitAndThrow.h"
#include "../GameObject/Aladdin.h"
#include "Sit.h"
US_NS_JK

IdleToSit::IdleToSit(Node* node):State(node)
{
}

IdleToSit::~IdleToSit()
{
}

void IdleToSit::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()

	auto aladdin = static_cast<Aladdin*>(_node);
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

	aladdin->setActionName("IdleToSit");
}

State* IdleToSit::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new SitAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW) && !Input::getInstance()->isKeyUp(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (aladdin->getIndex() >= 3)
		return new Idle(_node);
	return nullptr;
}



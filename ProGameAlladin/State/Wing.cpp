#include "Wing.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "SlashWhenWing.h"
#include "ThrowWhenWing.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

Wing::Wing(Node* node):State(node)
{
}

Wing::~Wing()
{
}

void Wing::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("Wing");
}

State* Wing::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenWing(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new ThrowWhenWing(_node);

	return nullptr;
}

#include "ThrowWhenWing.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
US_NS_JK

ThrowWhenWing::ThrowWhenWing(Node* node):State(node)
{
}

ThrowWhenWing::~ThrowWhenWing()
{
}

void ThrowWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("ThrowWhenWing");
}

State* ThrowWhenWing::checkTransition()
{
	return nullptr;
}

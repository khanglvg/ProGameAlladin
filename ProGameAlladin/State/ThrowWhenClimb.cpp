#include "ThrowWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "SlashWhenClimb.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

ThrowWhenClimb::ThrowWhenClimb(Node* node):State(node)
{
}

ThrowWhenClimb::~ThrowWhenClimb()
{
}

void ThrowWhenClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("ThrowWhenClimb");
}

State* ThrowWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);


	return nullptr;
}

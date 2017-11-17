#include "SlashWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "ThrowWhenClimb.h"
#include "../Aladdin.h"
US_NS_JK

SlashWhenClimb::SlashWhenClimb(Node* node):State(node)
{
}

SlashWhenClimb::~SlashWhenClimb()
{
}

void SlashWhenClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("SlashWhenClimb");
}

State* SlashWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);

	return nullptr;
}

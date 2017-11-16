#include "SlashWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "ThrowWhenClimb.h"
US_NS_JK

SlashWhenClimb::SlashWhenClimb(Node* node):State(node)
{
}

SlashWhenClimb::~SlashWhenClimb()
{
}

void SlashWhenClimb::onEnter()
{
}

State* SlashWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);

	return nullptr;
}

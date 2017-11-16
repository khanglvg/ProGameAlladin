#include "ThrowWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "SlashWhenClimb.h"

US_NS_JK

ThrowWhenClimb::ThrowWhenClimb(Node* node):State(node)
{
}

ThrowWhenClimb::~ThrowWhenClimb()
{
}

void ThrowWhenClimb::onEnter()
{
}

State* ThrowWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);


	return nullptr;
}

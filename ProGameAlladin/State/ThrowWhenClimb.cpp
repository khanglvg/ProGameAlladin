#include "ThrowWhenClimb.h"

JaKa::ThrowWhenClimb::ThrowWhenClimb(Node* node):State(node)
{
}

JaKa::ThrowWhenClimb::~ThrowWhenClimb()
{
}

void JaKa::ThrowWhenClimb::onEnter()
{
}

JaKa::State* JaKa::ThrowWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);


	return nullptr;
}

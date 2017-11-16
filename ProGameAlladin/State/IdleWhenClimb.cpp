#include "IdleWhenClimb.h"
#include "../Framework/Input.h"
#include "SlashWhenClimb.h"
#include "ThrowWhenClimb.h"
US_NS_JK

IdleWhenClimb::IdleWhenClimb(Node* node):State(node)
{
}

IdleWhenClimb::~IdleWhenClimb()
{
}

void IdleWhenClimb::onEnter()
{
}

State* IdleWhenClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);

	return nullptr;
}

#include "JumpWhileClimb.h"

US_NS_JK
JaKa::JumpWhileClimb::JumpWhileClimb(Node* node):State(node)
{
}

JaKa::JumpWhileClimb::~JumpWhileClimb()
{
}

void JaKa::JumpWhileClimb::onEnter()
{
}

JaKa::State* JaKa::JumpWhileClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Fall(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Fall(_node);

	return nullptr;
}

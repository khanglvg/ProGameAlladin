#include "RunAndJump.h"
US_NS_JK

RunAndJump::RunAndJump(Node* node):State(_node)
{
}

RunAndJump::~RunAndJump()
{
}

void RunAndJump::onEnter()
{
}

State* RunAndJump::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	return nullptr;
}

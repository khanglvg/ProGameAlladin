#include "Jump.h"
US_NS_JK

Jump::Jump(Node* node):State(_node)
{
}

Jump::~Jump()
{
}

void Jump::onEnter()
{
}

State* Jump::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return JumpAndSlash(_node);

	return nullptr;
}

#include "Jump.h"
US_NS_JK

Jump::Jump(Node* node):State(node)
{
}

Jump::~Jump()
{
}

void Jump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Jump::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	return nullptr;
}

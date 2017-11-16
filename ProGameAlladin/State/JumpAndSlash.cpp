#include "JumpAndSlash.h"
US_NS_JK

JumpAndSlash::JumpAndSlash(Node* node):State(node)
{
}

JumpAndSlash::~JumpAndSlash()
{
}

void JumpAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* JumpAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);

	return nullptr;
}

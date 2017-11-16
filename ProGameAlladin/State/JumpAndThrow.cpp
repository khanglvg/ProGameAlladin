#include "JumpAndThrow.h"
US_NS_JK

JumpAndThrow::JumpAndThrow(Node* node):State(node)
{
}

JumpAndThrow::~JumpAndThrow()
{
}

void JumpAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* JumpAndThrow::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	return nullptr;
}

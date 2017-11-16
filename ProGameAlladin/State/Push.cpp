#include "Push.h"
US_NS_JK

Push::Push(Node* node):State(node)
{
}

Push::~Push()
{
}

void Push::onEnter()
{
}

State* Push::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);

	return nullptr;
}

#include "RunAndSlash.h"
US_NS_JK

RunAndSlash::RunAndSlash(Node* node):State(node)
{
}

RunAndSlash::~RunAndSlash()
{
}

void RunAndSlash::onEnter()
{
}

JaKa::State* RunAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);

	return nullptr;
}

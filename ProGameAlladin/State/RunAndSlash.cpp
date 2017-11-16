#include "RunAndSlash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "RunAndJump.h"
US_NS_JK

RunAndSlash::RunAndSlash(Node* node):State(node)
{
}

RunAndSlash::~RunAndSlash()
{
}

void RunAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* RunAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);

	return nullptr;
}

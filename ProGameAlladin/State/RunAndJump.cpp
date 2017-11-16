#include "RunAndJump.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
US_NS_JK

RunAndJump::RunAndJump(Node* node):State(node)
{
}

RunAndJump::~RunAndJump()
{
}

void RunAndJump::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* RunAndJump::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	return nullptr;
}

#include "Fall.h"
#include "../Framework/Input.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
US_NS_JK

Fall::Fall(Node* node):State(node)
{
}

Fall::~Fall()
{
}

void Fall::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Fall::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);


	return nullptr;
}

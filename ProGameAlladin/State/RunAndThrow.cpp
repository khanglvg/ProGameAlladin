#include "RunAndThrow.h"
US_NS_JK

RunAndThrow::RunAndThrow(Node* node):State(node)	
{
}

RunAndThrow::~RunAndThrow()
{
}

void RunAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* RunAndThrow::checkTransition()
{
	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		return new Idle(_node);

	return nullptr;
}

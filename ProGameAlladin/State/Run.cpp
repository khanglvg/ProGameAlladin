#include "Run.h"

US_NS_JK

Run::Run(Node* node):State(node)
{
}

Run::~Run()
{
}

void Run::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Run::checkTransition()
{
	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new RunAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new RunAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);


	
	return nullptr;
}

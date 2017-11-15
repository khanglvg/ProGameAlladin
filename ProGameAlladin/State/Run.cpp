#include "Run.h"

US_NS_JK

Run::Run()
{
}

Run::~Run()
{
}

void Run::onEnter()
{
}

State* Run::checkTransition()
{
	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle();
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		return new Idle();
	if (Input::getInstance()->getKey(KEY_A))
		return new RunAndThrow();
	if (Input::getInstance()->getKey(KEY_S))
		return new RunAndSlash();
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump();


	
	return nullptr;
}

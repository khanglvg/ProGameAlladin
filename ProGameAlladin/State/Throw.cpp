#include "Throw.h"

US_NS_JK

Throw::Throw()
{
}

Throw::~Throw()
{
}

void Throw::onEnter()
{
}

State* Throw::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash();
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump();
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run();
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run();

	return nullptr;
}

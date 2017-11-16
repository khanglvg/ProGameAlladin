#include "Idle.h"

US_NS_JK


Idle::Idle(Node* node):State(node)
{
}

Idle::~Idle()
{
}

void Idle::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Idle::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	
	return nullptr;
}

#include "Wing.h"

US_NS_JK

Wing::Wing(Node* node):State(node)
{
}

Wing::~Wing()
{
}

void Wing::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Wing::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenWing(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenWing(_node);

	return nullptr;
}

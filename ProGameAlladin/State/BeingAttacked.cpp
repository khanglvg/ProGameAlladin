#include "BeingAttacked.h"
US_NS_JK

BeingAttacked::BeingAttacked(Node* node):State(node)
{
}

BeingAttacked::~BeingAttacked()
{
}

void BeingAttacked::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* BeingAttacked::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);

		return nullptr;

}

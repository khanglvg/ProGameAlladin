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
}

JaKa::State* JaKa::BeingAttacked::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash();
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump();
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp();
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit();
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run();
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run();

		return nullptr;

}

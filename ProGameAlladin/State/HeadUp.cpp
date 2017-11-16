#include "HeadUp.h"
US_NS_JK

HeadUp::HeadUp(Node* node):State(node)
{
}

HeadUp::~HeadUp()
{
}

void HeadUp::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* HeadUp::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new HeadUpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);

	return nullptr;
}

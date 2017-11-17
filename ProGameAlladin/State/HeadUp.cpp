#include "HeadUp.h"
#include "State.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "Sit.h"
#include "HeadUpAndSlash.h"
#include "Throw.h"
#include "Idle.h"

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
	/*if (Input::getInstance()->getKey(KEY_DOWN_ARROW) && Input::getInstance()->isAnyKeyDown())
		return new Sit(_node);*/
	if (Input::getInstance()->getKey(KEY_S))
		return new HeadUpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW))
		return new Idle(_node);

	return nullptr;
}

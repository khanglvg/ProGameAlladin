#include "HeadUpAndSlash.h"
#include "../Framework/Input.h"
#include "Run.h"
#include "Jump.h"
#include "HeadUp.h"
#include "IdleToSit.h"
#include "Throw.h"
US_NS_JK

HeadUpAndSlash::HeadUpAndSlash(Node* node):State(node)
{
}

HeadUpAndSlash::~HeadUpAndSlash()
{
}

void HeadUpAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* HeadUpAndSlash::checkTransition()
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
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);

	return nullptr;
}

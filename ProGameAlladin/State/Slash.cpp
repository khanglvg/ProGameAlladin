#include "Slash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "Jump.h"
#include "Run.h"
#include "HeadUp.h"
#include "Sit.h"
US_NS_JK


Slash::Slash(Node* node):State(node)
{
}

Slash::~Slash()
{
}

void Slash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Slash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Sit(_node);

	return nullptr;
}

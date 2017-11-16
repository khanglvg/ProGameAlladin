#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "Jump.h"
#include "Run.h"

US_NS_JK

Throw::Throw(Node* node):State(node)
{
}

Throw::~Throw()
{
}

void Throw::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Throw::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);

	return nullptr;
}

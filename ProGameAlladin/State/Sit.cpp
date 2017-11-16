#include "Sit.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "SitAndSlash.h"
#include "SitAndThrow.h"
US_NS_JK

Sit::Sit(Node* node):State(node)
{
}

Sit::~Sit()
{
}

void Sit::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Sit::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new SitAndThrow(_node);

	return nullptr;
}

#include "SitAndSlash.h"
US_NS_JK

SitAndSlash::SitAndSlash(Node* node):State(node)
{
}

SitAndSlash::~SitAndSlash()
{
}

void SitAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* SitAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new SitAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);

		return nullptr;
}

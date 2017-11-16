#include "SitAndThrow.h"
US_NS_JK

SitAndThrow::SitAndThrow(Node* node):State(node)
{
}

SitAndThrow::~SitAndThrow()
{
}

void SitAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* SitAndThrow::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);



	return nullptr;
}

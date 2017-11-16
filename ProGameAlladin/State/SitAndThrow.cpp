#include "SitAndThrow.h"
US_NS_JK

void SitAndThrow::onEnter()
{
}

State * SitAndThrow::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash();
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump();



	return nullptr;
}

#include "SitAndSlash.h"
US_NS_JK
JaKa::State* JaKa::SitAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new SitAndThrow();
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump();

		return nullptr;
}

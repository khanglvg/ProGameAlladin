#include "Fall.h"
US_NS_JK

JaKa::State* JaKa::Fall::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow();
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash();


	return nullptr;
}

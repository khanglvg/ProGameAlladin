#include "RunAndSlash.h"
US_NS_JK

JaKa::State* JaKa::RunAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw();
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump();

	return nullptr;
}

#include "Brake.h"
US_NS_JK

JaKa::State* JaKa::Brake::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw();
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash();
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump();

	return nullptr;
}

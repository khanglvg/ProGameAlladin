#include "Brake.h"
US_NS_JK

Brake::Brake(Node* node):State(node)
{
}

Brake::~Brake()
{
}

void Brake::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

JaKa::State* JaKa::Brake::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);

	return nullptr;
}

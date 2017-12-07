#include "Idle3.h"
#include "../Aladdin.h"
US_NS_JK
JaKa::Idle3::Idle3(Node* node):State(node)
{
}

JaKa::Idle3::~Idle3()
{
}

void JaKa::Idle3::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Idle3");
}

State* Idle3::checkTransition()
{
	return nullptr;
}

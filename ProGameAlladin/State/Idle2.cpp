#include "Idle2.h"
#include "../Aladdin.h"

US_NS_JK
JaKa::Idle2::Idle2(Node* node):State(node)
{
}

JaKa::Idle2::~Idle2()
{
}

void JaKa::Idle2::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Idle2");
}

State* Idle2::checkTransition()
{
	return nullptr;
}

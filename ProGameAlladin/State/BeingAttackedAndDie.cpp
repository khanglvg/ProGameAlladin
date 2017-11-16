#include "BeingAttackedAndDie.h"
US_NS_JK

BeingAttackedAndDie::BeingAttackedAndDie(Node* node):State(node)
{
}

BeingAttackedAndDie::~BeingAttackedAndDie()
{
}

void BeingAttackedAndDie::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* BeingAttackedAndDie::checkTransition()
{
	return nullptr;
}

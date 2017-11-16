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
}

JaKa::State* JaKa::BeingAttackedAndDie::checkTransition()
{
	return nullptr;
}

#include "IdleWhenWing.h"
#include "../GameObject/Aladdin.h"
US_NS_JK

IdleWhenWing::IdleWhenWing(Node* node):State(node)
{
}

IdleWhenWing::~IdleWhenWing()
{
}

void IdleWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("IdleWhenClimbing");
}

State* IdleWhenWing::checkTransition()
{
	return nullptr;
}

#include "IdleWhenWing.h"
US_NS_JK

IdleWhenWing::IdleWhenWing(Node* node):State(node)
{
}

IdleWhenWing::~IdleWhenWing()
{
}

void IdleWhenWing::onEnter()
{
}

State* IdleWhenWing::checkTransition()
{
	return nullptr;
}

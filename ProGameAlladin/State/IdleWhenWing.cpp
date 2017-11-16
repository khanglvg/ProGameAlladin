#include "IdleWhenWing.h"
US_NS_JK

JaKa::IdleWhenWing::IdleWhenWing(Node* node):State(node)
{
}

JaKa::IdleWhenWing::~IdleWhenWing()
{
}

void JaKa::IdleWhenWing::onEnter()
{
}

JaKa::State* JaKa::IdleWhenWing::checkTransition()
{
	return nullptr;
}

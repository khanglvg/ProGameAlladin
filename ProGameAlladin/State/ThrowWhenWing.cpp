#include "ThrowWhenWing.h"
US_NS_JK

ThrowWhenWing::ThrowWhenWing(Node* node):State(node)
{
}

ThrowWhenWing::~ThrowWhenWing()
{
}

void ThrowWhenWing::onEnter()
{
}

State* ThrowWhenWing::checkTransition()
{
	return nullptr;
}

#include "ThrowWhenWing.h"
US_NS_JK

JaKa::ThrowWhenWing::ThrowWhenWing(Node* node):State(node)
{
}

JaKa::ThrowWhenWing::~ThrowWhenWing()
{
}

void JaKa::ThrowWhenWing::onEnter()
{
}

State* ThrowWhenWing::checkTransition()
{
	return nullptr;
}

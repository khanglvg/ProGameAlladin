#include "Climb.h"
US_NS_JK

Climb::Climb(Node* node):State(node)
{
}

Climb::~Climb()
{
}

void Climb::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
}

State* Climb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);

	return nullptr;
}

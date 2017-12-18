#include "Grounding.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"

US_NS_JK

Grounding::Grounding(Node* node):State(node)
{
}

Grounding::~Grounding()
{
}

void Grounding::onEnter()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setActionName("Grounding");
	//aladdin->setOrigin(Vec2(0.5f, 1.0f));
}

State*Grounding::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Idle(_node);
	if (aladdin->getIndex()>=11)
		return new Idle(_node);
	return nullptr;
}

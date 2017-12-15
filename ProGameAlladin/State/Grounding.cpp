#include "Grounding.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

JaKa::Grounding::Grounding(Node* node):State(node)
{
}

JaKa::Grounding::~Grounding()
{
}

void JaKa::Grounding::onEnter()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setActionName("Grounding");
	aladdin->setOrigin(Vec2(0.5f, 1.0f));

}

JaKa::State* JaKa::Grounding::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (aladdin->getIndex()>=11)
		return new Idle(_node);
	return nullptr;
}

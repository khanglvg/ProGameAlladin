#include "SlashWhenWing.h"
#include "../Aladdin.h"
#include "../Framework/Input.h"

US_NS_JK
SlashWhenWing::SlashWhenWing(Node* node):State(node)
{
}

SlashWhenWing::~SlashWhenWing()
{
}

void SlashWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("SlashWhenWing");
}

State* SlashWhenWing::checkTransition()
{
	return nullptr;
}

#include "SlashWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "ThrowWhenClimb.h"
#include "../GameObject/Aladdin.h"
#include "IdleToClimb.h"
US_NS_JK

SlashWhenClimb::SlashWhenClimb(Node* node):State(node)
{
}

SlashWhenClimb::~SlashWhenClimb()
{
}

void SlashWhenClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setVelocity(Vec2(0, 0));


	aladdin->setActionName("SlashWhenClimbing");

}

void SlashWhenClimb::onUpdate()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

}

State* SlashWhenClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);
	if (aladdin->getIndex() >= 6)
		return new IdleToClimb(_node);
	
	return nullptr;
}

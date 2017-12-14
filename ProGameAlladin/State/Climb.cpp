#include "Climb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "../GameObject/Aladdin.h"
#include "SlashWhenClimb.h"
#include "ThrowWhenClimb.h"
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
	auto aladdin = static_cast<Aladdin*>(_node);
	
	
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
	{
		//aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(0,- 100));
	}
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
	{
		//aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(0, 100));
	}
	aladdin->setActionName("Climb");
}

State* Climb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new ThrowWhenClimb(_node);

	return nullptr;
}

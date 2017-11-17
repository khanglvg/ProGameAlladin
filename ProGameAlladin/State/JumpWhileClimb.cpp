#include "JumpWhileClimb.h"
#include "../Framework/Input.h"
#include "JumpAndSlash.h"
#include "JumpAndThrow.h"
#include "Fall.h"
#include "../Aladdin.h"

US_NS_JK
JumpWhileClimb::JumpWhileClimb(Node* node):State(node)
{
}

JumpWhileClimb::~JumpWhileClimb()
{
}

void JumpWhileClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("JumpWhileClimp");
}

State* JumpWhileClimb::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new JumpAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Fall(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Fall(_node);

	return nullptr;
}

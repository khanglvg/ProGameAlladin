#include "JumpAndThrow.h"
#include "../Framework/Input.h"
#include "JumpAndSlash.h"
#include "../GameObject/Aladdin.h"
US_NS_JK

JumpAndThrow::JumpAndThrow(Node* node):State(node)
{
}

JumpAndThrow::~JumpAndThrow()
{
}

void JumpAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("JumpWhileThrow");
}

State* JumpAndThrow::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	return nullptr;
}

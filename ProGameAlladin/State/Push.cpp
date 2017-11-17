#include "Push.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "../Aladdin.h"

US_NS_JK

Push::Push(Node* node):State(node)
{
}

Push::~Push()
{
}

void Push::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setActionName("Push"); // Idle to push

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));
}

State* Push::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);

	return nullptr;
}

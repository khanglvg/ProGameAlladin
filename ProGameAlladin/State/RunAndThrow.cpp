#include "RunAndThrow.h"
#include "../Framework/Input.h"
#include "Idle.h"
#include "../Aladdin.h"
US_NS_JK

RunAndThrow::RunAndThrow(Node* node):State(node)	
{
}

RunAndThrow::~RunAndThrow()
{
}

void RunAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("RunAndThrow");
}

State* RunAndThrow::checkTransition()
{
	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		return new Idle(_node);

	return nullptr;
}

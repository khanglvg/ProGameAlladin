#include "RunAndSlash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "RunAndJump.h"
#include "../Aladdin.h"
US_NS_JK

RunAndSlash::RunAndSlash(Node* node):State(node)
{
}

RunAndSlash::~RunAndSlash()
{
}

void RunAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("RunAndSlash");
}

State* RunAndSlash::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);

	return nullptr;
}

#include "IdleToLook.h"
#include "HeadUp.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "HeadUpAndSlash.h"
#include "Throw.h"
#include "Idle.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

JaKa::IdleToLook::IdleToLook(Node* node):State(node)
{

}

JaKa::IdleToLook::~IdleToLook()
{
}

void JaKa::IdleToLook::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("IdleToLook");
}


JaKa::State* JaKa::IdleToLook::checkTransition()
{
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	/*if (Input::getInstance()->getKey(KEY_DOWN_ARROW) && Input::getInstance()->isAnyKeyDown())
	return new Sit(_node);*/
	if (Input::getInstance()->getKey(KEY_S))
		return new HeadUpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW) && !Input::getInstance()->isKeyUp(KEY_UP_ARROW))
		return new HeadUp(_node);
	return nullptr;
}

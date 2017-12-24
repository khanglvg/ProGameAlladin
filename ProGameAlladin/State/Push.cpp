#include "Push.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "../GameObject/Aladdin.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"

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
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	Audio::get()->play(lv1->getsoundPushing(), false);
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

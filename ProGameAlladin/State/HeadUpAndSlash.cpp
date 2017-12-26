#include "HeadUpAndSlash.h"
#include "../Framework/Input.h"
#include "Run.h"
#include "Jump.h"
#include "HeadUp.h"
#include "IdleToSit.h"
#include "Throw.h"
#include "../GameObject/Aladdin.h"
#include "Flip.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"
US_NS_JK

HeadUpAndSlash::HeadUpAndSlash(Node* node):State(node)
{

}

HeadUpAndSlash::~HeadUpAndSlash()
{
}

void HeadUpAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	const auto aladdin = static_cast<Aladdin*>(_node);
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());

	Audio::get()->play(lv1->getsoundSlash(), false);

	
	aladdin->setActionName("HeadUpAndSlash");
}

State* HeadUpAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_Q))
		return new Flip(_node);
	if (aladdin->getIndex() >= 22)
		return new Idle(_node);
	
	return nullptr;
}

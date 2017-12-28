#include "BeingAttacked.h"
#include "Throw.h"
#include "Jump.h"
#include "Slash.h"
#include "HeadUp.h"
#include "Run.h"
#include "IdleToSit.h"
#include "../Framework/Input.h"
#include "../GameObject/Aladdin.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"
#include "../BossScene.h"
#include "IdleToLook.h"

US_NS_JK

BeingAttacked::BeingAttacked(Node* node):State(node)
{
}

BeingAttacked::~BeingAttacked()
{

}

void BeingAttacked::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("BeingAttacked");
	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	auto boss = static_cast<BossScene*>(aladdin->getCurrentScene());
	if (aladdin->getEScene() == Aladdin::ENUM_LV1_SCENE)
	{
		Audio::get()->play(lv1->getsoundHurt(), false);
	}



	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		Audio::get()->play(boss->getsoundHurt(), false);
	}
}

State* BeingAttacked::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new IdleToLook(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (aladdin->getIndex() == 6)
		return new Idle(_node);
	return nullptr;

}

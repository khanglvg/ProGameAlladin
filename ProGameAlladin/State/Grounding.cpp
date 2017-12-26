#include "Grounding.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "../Framework/Audio.h"
#include "../Lv1Scene.h"
#include "../BossScene.h"

US_NS_JK

Grounding::Grounding(Node* node):State(node)
{
}

Grounding::~Grounding()
{
}

void Grounding::onEnter()
{

	const auto aladdin = static_cast<Aladdin*>(_node);

	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	auto boss = static_cast<BossScene*>(aladdin->getCurrentScene());

	if (aladdin->getEScene() == Aladdin::ENUM_LV1_SCENE)
	{
		Audio::get()->play(lv1->getsoundGrounding(), false);
	}



	if (aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
	{
		Audio::get()->play(boss->getsoundGrounding(), false);
	}

	aladdin->setActionName("Grounding");

}




State*Grounding::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Idle(_node);

	if (aladdin->getIndex()>=11)
	{
		
		return new Idle(_node);
	}
		
	return nullptr;
}

#include "Idle2.h"
#include "../GameObject/Aladdin.h"
#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "IdleToSit.h"
#include "HeadUp.h"
#include "Jump.h"
#include "Run.h"
#include "BeingAttacked.h"

US_NS_JK
JaKa::Idle2::Idle2(Node* node):State(node)
{
}

JaKa::Idle2::~Idle2()
{
}

void JaKa::Idle2::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Idle2");
	aladdin->setVelocity(Vec2(0, 0));

}

State* Idle2::checkTransition()
{
	auto const aladdin = static_cast<Aladdin*>(_node);



	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->isKeyDown(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);
	if (aladdin->isAttacked())
		return new BeingAttacked(_node);

	return nullptr;
}

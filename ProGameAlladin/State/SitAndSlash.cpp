#include "SitAndSlash.h"
#include "../Framework/Input.h"
#include "SitAndThrow.h"
#include "Jump.h"
#include "../Aladdin.h"
#include "Sit.h"
US_NS_JK

SitAndSlash::SitAndSlash(Node* node):State(node)
{
}

SitAndSlash::~SitAndSlash()
{
}

void SitAndSlash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-0, aladdin->getVelocity().getY()));
	}

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}

	aladdin->setActionName("SitAndSlash");
}

void SitAndSlash::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));
}

State* SitAndSlash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_A))
		return new SitAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (!Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Idle(_node);
	if (aladdin->getIndex() >= 6)
		return new Sit(_node);

		return nullptr;
}

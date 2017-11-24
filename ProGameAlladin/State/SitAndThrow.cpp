#include "SitAndThrow.h"
#include "../Framework/Input.h"
#include "SitAndSlash.h"
#include "Jump.h"
#include "../Aladdin.h"
#include "Sit.h"
US_NS_JK

SitAndThrow::SitAndThrow(Node* node):State(node)
{
}

SitAndThrow::~SitAndThrow()
{
}

void SitAndThrow::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("SitAndThrow");
}

State* SitAndThrow::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (!Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Idle(_node);

	if (aladdin->getIndex() >= 4)
		return new Sit(_node);



	return nullptr;
}

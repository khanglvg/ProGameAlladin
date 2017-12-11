#include "Slash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "Jump.h"
#include "Run.h"
#include "HeadUp.h"
#include "IdleToSit.h"
#include "../GameObject/Aladdin.h"
US_NS_JK


Slash::Slash(Node* node):State(node)
{
}

Slash::~Slash()
{
}

void Slash::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	//if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	//	aladdin->setScale(Vec2(-1, 1));

	//if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	//	aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("Slash");
}

State* Slash::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new Throw(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);

	if (aladdin->getIndex() >= 4)
	{
		return new Idle(_node);
	}

	return nullptr;
}

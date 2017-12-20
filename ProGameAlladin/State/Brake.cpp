#include "Brake.h"
#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "Jump.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

Brake::Brake(Node* node):State(node)
{
}

Brake::~Brake()
{
}

void Brake::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("Run 3s then brake");
}

State* Brake::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	//if (Input::getInstance()->getKey(KEY_A))
	//	return new Throw(_node);
	//if (Input::getInstance()->getKey(KEY_S))
	//	return new Slash(_node);
	//if (Input::getInstance()->getKey(KEY_D))
	//	return new Jump(_node);
	if (aladdin->getIndex() >= 8)
		return new Idle(_node);

	return nullptr;
}

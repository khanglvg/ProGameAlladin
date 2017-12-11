#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "Jump.h"
#include "Run.h"
<<<<<<< HEAD
#include "../GameObject/Aladdin.h"
=======
#include "../Aladdin.h"
#include "../AppleToThrow.h"
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16

US_NS_JK

Throw::Throw(Node* node):State(node)
{
}

Throw::~Throw()
{
}

void Throw::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("Throw");

	auto apple = new AppleToThrow();
	apple->init();
	apple->setVelocity(Vec2(20, 0));
	
}

void Throw::onExit()
{

}

State* Throw::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);

	//if(aladdin->getIndex() >= 5)
	//{
	//	return new Idle(_node);
	//}

	return nullptr;
}

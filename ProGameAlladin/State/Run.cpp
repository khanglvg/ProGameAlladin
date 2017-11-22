#include "Run.h"
#include "../Framework/Input.h"
#include "Idle.h"
#include "RunAndThrow.h"
#include "RunAndSlash.h"
#include "RunAndJump.h"
#include "../Aladdin.h"
#include "IdleToSit.h"
#include "HeadUp.h"
#include "Push.h"

US_NS_JK

Run::Run(Node* node):State(node)
{
}

Run::~Run()
{
}

void Run::onEnter()
{
	// TODO: setScale()
	// TODO: loadAnimation()
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	aladdin->setActionName("Run");
}

void Run::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	//if (Input::getInstance()->getKey(KEY_LEFT_ARROW)) {
	//	//aladdin->setPosition(Vec2(aladdin->getPosition().getX() - aladdin->getVelocity().getX(), aladdin->getPosition().getY()));
	//}
	//if (Input::getInstance()->getKey(KEY_RIGHT_ARROW)) {
	//	//aladdin->setPosition(Vec2(aladdin->getPosition().getX() + aladdin->getVelocity().getX(), aladdin->getPosition().getY()));
	//}
}

State* Run::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW) )
		return new Idle(_node);
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) )
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new IdleToSit(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW))
		return new HeadUp(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new RunAndThrow(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new RunAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new RunAndJump(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW) && aladdin->getPosition().getX() < aladdin->getXGround() - 82)
		return new Push(_node);
	
	return nullptr;
}

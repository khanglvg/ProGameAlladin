#include "Throw.h"
#include "../Framework/Input.h"
#include "Slash.h"
#include "Jump.h"
#include "Run.h"
#include "../GameObject/Aladdin.h"
#include "../GameObject/AppleToThrow.h"

#include "../Framework/Scene.h"
#include "../GameObject/Enemies/KnifeEnemy/KnifeToThrow.h"
#include "JumpAndThrow.h"

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

	if (Input::getInstance()->getKey(KEY_A))
	{
		const auto apple = new AppleToThrow(aladdin, Vec2(aladdin->getRigidPosition().getX(), aladdin->getRigidPosition().getY() - 20), Size(5,5));
		if(aladdin->getScale() == Vec2(1,1))
		{
			apple->getRigidBody()->setVelocity(Vec2(400, 0));
		}
		else
		{
			apple->getRigidBody()->setVelocity(Vec2(-400, 0));
		}
		
		apple->setCurrentScene(aladdin->getCurrentScene());
		aladdin->getCurrentScene()->addNode(apple);
	}

	
	
}

void Throw::onExit()
{

}

State* Throw::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new Slash(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		return new Run(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		return new Run(_node);

	if(!Input::getInstance()->getKey(KEY_A) && aladdin->getIndex() >= 5)
	{
		return new Idle(_node);
	}

	return nullptr;
}

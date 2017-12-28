#include "ThrowWhenWing.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "IdleWhenWing.h"
#include "../Framework/Scene.h"
#include "../GameObject/Weapons/AppleToThrow.h"
US_NS_JK

ThrowWhenWing::ThrowWhenWing(Node* node):State(node)
{
}

ThrowWhenWing::~ThrowWhenWing()
{
}

void ThrowWhenWing::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	aladdin->setActionName("ThrowWhenClimbing");

	if (Input::getInstance()->getKey(KEY_A))
	{
		const auto apple = new AppleToThrow(aladdin, Vec2(aladdin->getRigidPosition().getX(), aladdin->getRigidPosition().getY() - 20), Size(5, 5));
		if (aladdin->getScale() == Vec2(-1, 1))
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

void ThrowWhenWing::onExit()
{
}

State* ThrowWhenWing::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (aladdin->getIndex() >= 4)
		return new IdleWhenWing(_node);

	return nullptr;
}

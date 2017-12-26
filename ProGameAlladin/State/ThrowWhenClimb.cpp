#include "ThrowWhenClimb.h"
#include "../Framework/Input.h"
#include "JumpWhileClimb.h"
#include "SlashWhenClimb.h"
#include "../GameObject/Aladdin.h"
#include "IdleToClimb.h"
#include "../Framework/Scene.h"
#include "../GameObject/Weapons/AppleToThrow.h"
#include "../Framework/Audio.h"
#include "../Lv1Scene.h"

US_NS_JK

ThrowWhenClimb::ThrowWhenClimb(Node* node):State(node)
{
}

ThrowWhenClimb::~ThrowWhenClimb()
{
}

void ThrowWhenClimb::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	Audio::get()->play(lv1->getsoundThrowing(), false);

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

void ThrowWhenClimb::onUpdate()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
		aladdin->setScale(Vec2(1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
		aladdin->setScale(Vec2(-1, 1));

}

State* ThrowWhenClimb::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_D))
		return new JumpWhileClimb(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SlashWhenClimb(_node);
	if (aladdin->getIndex() >= 4)
		return new IdleToClimb(_node);


	return nullptr;
}

#include "Flip.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Input.h"
#include "Fall.h"
#include "JumpAndThrow.h"
#include "JumpAndSlash.h"
#include "../Lv1Scene.h"
#include "../Framework/Audio.h"
US_NS_JK


Flip::Flip(Node* node) :State(node)
{

}

Flip::~Flip()
{
}

void Flip::onEnter()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setVelocity(Vec2(0, -380));
	aladdin->getRigidBody()->setSize(Size(10, 60));
	aladdin->setActionName("Flip");

	auto lv1 = static_cast<Lv1Scene*>(aladdin->getCurrentScene());
	Audio::get()->play(lv1->getsoundSpring(), false);
}

void Flip::onUpdate()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-230, aladdin->getVelocity().getY()));

	}

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(230, aladdin->getVelocity().getY()));
	}

	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) || Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW))
	{
		aladdin->setVelocity(Vec2(0, aladdin->getVelocity().getY()));
	}
}

void Flip::onExit()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->getRigidBody()->setGravityScale(1.5);
}

State* Flip::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new JumpAndThrow(_node);

	if (Input::getInstance()->getKey(KEY_S))
		return new JumpAndSlash(_node);

	if (aladdin->isOnTheGround()||aladdin->isOnThePlatform())
		return new Idle(_node);

	if (aladdin->isInSpringBoard())
	{
		return new Flip(_node);
	}

	if(aladdin->getIndex()>=10&&aladdin->getIndex()<12)
		aladdin->getRigidBody()->setGravityScale(2.7);

	if(aladdin->getIndex()>=12)
	{
		return new Fall(_node);
	}

	return nullptr;
}

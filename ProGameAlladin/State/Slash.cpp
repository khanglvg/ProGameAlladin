#include "Slash.h"
#include "../Framework/Input.h"
#include "Throw.h"
#include "Jump.h"
#include "Run.h"
#include "HeadUp.h"
#include "IdleToSit.h"
#include "../Framework/Scene.h"
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


	aladdin->setActionName("Slash");

	_weapon = new Weapon(aladdin, aladdin->getRigidPosition(), Size(10, 30), Vec2(30,12), "aladdinknife");

	if (aladdin->isOwnerRight())
	{
		_weapon->getOwner()->setIsOwnerRight(true);
		_weapon->getRigidBody()->setActive(true);
	}
	else
	{
		_weapon->getOwner()->setIsOwnerRight(false);
		_weapon->getRigidBody()->setActive(true);
	}

	_weapon->setCurrentScene(aladdin->getCurrentScene());
	aladdin->getCurrentScene()->addNode(_weapon);
}

void Slash::onExit()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	_weapon->getRigidBody()->setActive(false);
	aladdin->getCurrentScene()->removeNode(_weapon);
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

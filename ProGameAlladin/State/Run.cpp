#include "Run.h"
#include "../Framework/Input.h"
#include "Idle.h"
#include "RunAndThrow.h"
#include "RunAndSlash.h"
#include "RunAndJump.h"
#include "../GameObject/Aladdin.h"
#include "IdleToSit.h"
#include "HeadUp.h"
#include "Push.h"
#include "Idle3.h"
#include "Idle2.h"
#include "Random.h"
#include "../Framework/Camera.h"

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
	//auto camera = Camera::getInstance();
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-200, aladdin->getVelocity().getY()));
		//camera->setCameraX(aladdin->getPosition().getX() - camera->getWidth() / 2);
	}
	
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(200, aladdin->getVelocity().getY()));
		//camera->setCameraX(aladdin->getPosition().getX() + camera->getWidth() / 2);
		if(aladdin->isBesideTheStair())
		{
			aladdin->getRigidBody()->setPosition(Vec2(aladdin->getRigidBody()->getPosition().getX(), aladdin->getRigidBody()->getPosition().getY() - 5));
		}
	}

	aladdin->setActionName("Run");

	
}

void Run::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	//auto camera = Camera::getInstance();

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setScale(Vec2(-1, 1));
		aladdin->setVelocity(Vec2(-200, aladdin->getVelocity().getY()));
		//camera->setCameraY(150);
		if (aladdin->isBesideTheStair())
		{
			//aladdin->getRigidBody()->setPosition(Vec2(aladdin->getRigidBody()->getPosition().getX(), aladdin->getRigidBody()->getPosition().getY() - 1));
		}
	}

		if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setScale(Vec2(1, 1));
		aladdin->setVelocity(Vec2(200, aladdin->getVelocity().getY()));
		//camera->setCameraX(aladdin->getPosition().getX() + camera->getWidth() / 2);
		if (aladdin->isBesideTheStair())
		{
			aladdin->getRigidBody()->setPosition(Vec2(aladdin->getRigidBody()->getPosition().getX(), aladdin->getRigidBody()->getPosition().getY() - 1));
		}
	}
	
}

State* Run::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);

	if (Input::getInstance()->isKeyUp(KEY_RIGHT_ARROW) )
	{
			Random::getInstance()->generateRdnum();
		int _temp = Random::getInstance()->getRdNumb();
		{
			if (0 <= _temp && _temp<33)
			{
				return new Idle(_node);
			}

			if (33 <= _temp && _temp< 66)
			{
				return new Idle2(_node);
			}
			if (66 <= _temp&& _temp <= 100)
			{
				return new Idle3(_node);
			}
		}
	}
	if (Input::getInstance()->isKeyUp(KEY_LEFT_ARROW) )
	{
			Random::getInstance()->generateRdnum();
		int _temp = Random::getInstance()->getRdNumb();
		if (0 <= _temp && _temp<33)
		{
			return new Idle(_node);
		}

		if (33 <= _temp && _temp< 66)
		{
			return new Idle2(_node);
		}
		if (66 <= _temp&& _temp <= 100)
		{
			return new Idle3(_node);
		}
	}
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

	if (Input::getInstance()->getKey(KEY_LEFT_ARROW) && aladdin->isBesideTheWall())
		return new Push(_node);
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW) && aladdin->isBesideTheWall())
		return new Push(_node);

	
	return nullptr;
}

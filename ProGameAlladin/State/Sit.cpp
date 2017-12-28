#include "Sit.h"
#include "../GameObject/Aladdin.h"
#include "../Framework/Graphics.h"
#include "../Framework/Input.h"
#include "SitAndSlash.h"
#include "SitAndThrow.h"
US_NS_JK

Sit::Sit(Node* node):State(node)
{
}

Sit::~Sit()
{
}

void Sit::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);


	aladdin->setActionName("Sit");
	//aladdin->getRigidBody()->setSize(Size(10,aladdin->getRect().getHeight()));
	//aladdin->getRigidBody()->setOffset(Vec2(5,-30));
	//Graphics::getInstance()->drawSprite(aladdin->getTexture(), Vec2(0.3f, 1.0f), aladdin->getTransformMatrix(), Color(255, 255, 255, 255), Rect(378, 516, 52, 34), 1);
}

void Sit::onUpdate()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		aladdin->setIsOwnerRight(false);
		aladdin->setScale(Vec2(-1, 1));
	}
		
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		aladdin->setIsOwnerRight(true);
		aladdin->setScale(Vec2(1, 1));
	}
		

	
}

void Sit::onExit()
{
}

State* Sit::checkTransition()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	if (!Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new SitAndThrow(_node);


	


	return nullptr;
}

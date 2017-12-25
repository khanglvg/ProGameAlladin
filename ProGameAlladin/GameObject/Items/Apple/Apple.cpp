#include "Apple.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "AppleNormalState.h"
#include "../../Framework/Scene.h"
#include "../../Aladdin.h"
US_NS_JK

US_NS_JK

Apple::Apple()
{
}

Apple::Apple(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* target)
:Item(position, size, tag)
{
	//_rigid->setDensity(0.1);
	setScale(Vec2(1, 1));
	_rigid->setBodyType(STATIC);
	_rigid->setTag("apple");

	_currentState = new AppleNormalState(this);
	_isCollisionWithAladdin = false;
	_target = target;
	_isIncApple = false;
}

Apple::~Apple()
{
}

void Apple::init()
{
	_textureItem.setName("Apple.jpg");
	_textureItem.setSrcFile("Resources/Items/Items-Explosion.png");
	Graphics::getInstance()->loadTexture(_textureItem);


	_textureApple.setName("AppleRigid.png");
	_textureApple.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void Apple::release()
{
	delete _rigid;
	delete this;
}

void Apple::update()
{
	_rigid->setSize(Size(getRect().getWidth()*1.6+_rigid->getOffset().getX()*2, getRect().getHeight()));

	_position = _rigid->getPosition() - _rigid->getOffset();

	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if(aladdin == _rigid->getCollidingBodies().end())
	{
		_isCollisionWithAladdin =  false;
	}
	else
	{
		_isCollisionWithAladdin = true;
	}

	_currentState->onUpdate();

	ItemState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_animationIndex = 0;
	}


	if (aladdin != _rigid->getCollidingBodies().end())
	{
		_rigid->setActive(false);
		_isCollision = true;
		if (!_isIncApple)
		{
			_target->incApple();
			_isIncApple = true;
		}
	}		
	else
	{
		_isIncApple = false;
	}
}

void Apple::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	const auto origin = Vec2(0.5f, 1.0f);

	if (!_isCollision)
	{
		Graphics::getInstance()->drawSprite(_textureItem, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
	}
}

Rect Apple::getRect()
{
	const auto width = _animations[_actionName][_animationIndex].getWidth();
	const auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}


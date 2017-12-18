#include "Apple.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "AppleNormalState.h"
#include "../../Framework/Scene.h"
US_NS_JK

US_NS_JK

Apple::Apple()
{
}

Apple::Apple(const Vec2& position, const Size& size, const GameObjectType& tag)
:Item(position, size, tag)
{
	//_rigid->setDensity(0.1);
	setScale(Vec2(1, 1));
	_rigid->setTag("apple");

	_currentState = new AppleNormalState(this);
	_isCollisionWithAladdin = false;
}

Apple::~Apple()
{
}

void Apple::init()
{
	_textureItem.setName("Apple.jpg");
	_textureItem.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureItem);


	_textureApple.setName("AppleRigid.png");
	_textureApple.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void Apple::release()
{
	delete this;
}

void Apple::update()
{
	_rigid->setSize(Size(getRect().getWidth()*1.6+_rigid->getOffset().getX()*2, getRect().getHeight()));
	_position = _rigid->getPosition() -_rigid->getOffset();

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
	_position = _rigid->getPosition() - _rigid->getOffset();
	//auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (aladdin == _rigid->getCollidingBodies().end())
	{
	}
	else
		this->getCurrentScene()->removeNode(this);
}

void Apple::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	const auto expect = 0.05;

	
	auto origin = Vec2(0.3f, 1.0f);


	Graphics::getInstance()->drawSprite(_textureApple, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
	Graphics::getInstance()->drawSprite(_textureItem, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureItem, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size())
			_animationIndex = 0;

	}
	//Graphics::getInstance()->drawSprite(_textureRigidApple,
	//	Vec2(0.0f, 1.0f),
	//	getTransformMatrix(),
	//	Color(255, 255, 255, 255),
	//	Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()),
	//	2);

	//Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, 11, 12), 2);
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


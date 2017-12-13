#include "KnifeToThrow.h"
#include "../../../Framework/Graphics.h"
#include "../../../Framework/GameManager.h"
#include "../../../pugixml/pugixml.hpp"
US_NS_JK


KnifeToThrow::KnifeToThrow(const Vec2 & position, const Size & size) :GameObject(position, size, APPLES)
{
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(0.1);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("knifetothrow");

	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Enemies/KnifeToThrow.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			auto i = 0;
			for (auto rect : animation.children())
			{
				_animations.emplace(i++, Rect(rect.attribute("x").as_float(),
											  rect.attribute("y").as_float(),
											  rect.attribute("w").as_float(),
											  rect.attribute("h").as_float()));
			}
			
		}
	}
#pragma endregion 
}

KnifeToThrow::~KnifeToThrow()
{
}

void KnifeToThrow::init()
{
	_textureKnife.setName("KnifeToThrow.png");
	_textureKnife.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureKnife);
}

void KnifeToThrow::update()
{
	this->_position = _rigid->getPosition() - _rigid->getOffset();

	const auto aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");
	const auto ground = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "ground");

	if (aladdin == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else if (ground == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else
		_isCollision = true;

	if (_isCollision)
	{
		//getCurrentScene()->removeNode(this);
	}
}

void KnifeToThrow::release()
{
	delete _rigid;
	delete this;
}

void KnifeToThrow::render()
{
	if (_animationIndex == _animations.size())
		_animationIndex = 0;

	const auto rect = _animations[_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	const auto expect = 0.07;

	Graphics::getInstance()->drawSprite(_textureKnife, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureKnife, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations.size())
			_animationIndex = 0;

	}
}

Texture KnifeToThrow::getTexture() const
{
	return _textureKnife;
}

void KnifeToThrow::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool KnifeToThrow::isCollision() const
{
	return _isCollision;
}

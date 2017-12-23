#include "Fire.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/Scene.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"
#include "../Ground/FireGround.h"
#include "../Aladdin.h"

US_NS_JK

Fire::Fire(FireGround* owner, const Vec2 & position, const Size & size):GameObject(position,size, FIREGROUND)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.001);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("flame");

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/Flame.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			const pugi::char_t* name = animation.attribute("name").value();
			vector<Rect> rects;

			for (auto rect : animation.children())
			{
				rects.push_back(Rect(rect.attribute("x").as_float(),
					rect.attribute("y").as_float(),
					rect.attribute("w").as_float(),
					rect.attribute("h").as_float()));
			}
			_animations.emplace(name, rects);
		}
	}
#pragma endregion 
	setActionName("Flame");
}

Fire::~Fire()
{
}

void Fire::init()
{
	_textureFlame.setName("flame.png");
	_textureFlame.setSrcFile("Resources/Items/fire.png");
	Graphics::getInstance()->loadTexture(_textureFlame);
}

void Fire::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	const auto collisionWithAladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (collisionWithAladdin == _rigid->getCollidingBodies().end())
	{
		_isCollision = false;
	}
	else
	{
		_isCollision = true;
	}

	if ((abs(_owner->getTarget()->getPosition().getX() - _position.getX()) > 10 || !_isCollision) && _animationIndex == 8)
	{
		_owner->getCurrentScene()->removeNode(this);
	}
}

void Fire::release()
{
	delete _rigid;
	delete this;
}

void Fire::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.04;

	if (_animationIndex == 3 || _animationIndex == 4)
	{
		expect = 0.07;
	}

	Graphics::getInstance()->drawSprite(_textureFlame, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureFlame, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
			rect, 1);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (abs(_owner->getTarget()->getPosition().getX() - _position.getX()) > 10 || !_isCollision)
		{
			if (_animationIndex == _animations[_actionName].size())
			{
				_animationIndex = 0;
			}
		}
		else
		{
			if (_animationIndex >= 5)
			{
				_animationIndex = 3;
			}
		}
	}
}

Texture Fire::getTexture() const
{
	return _textureFlame;
}

void Fire::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool Fire::isCollision() const
{
	return _isCollision;
}

void Fire::setActionName(const string actionName)
{
	_actionName = actionName;
}

string Fire::getActionName() const
{
	return _actionName;
}

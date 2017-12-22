#include "TransformBullet.h"
#include "../../../../Framework/Graphics.h"
#include "../../../../Framework/Scene.h"
#include "../../../../Framework/Graphics.h"
#include "../../../../Framework/GameManager.h"
#include "../../../../pugixml/pugixml.hpp"

US_NS_JK

TransformBullet::TransformBullet(GameObject* owner, const Vec2 & position, const Size & size):GameObject(position,size, APPLES)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.000001);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(0.3);
	setPosition(_rigid->getPosition());
	setScale(Vec2(0.8, 0.8));
	_rigid->setTag("transformbullet");

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Boss/Flame.xml");

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

TransformBullet::~TransformBullet()
{
}

void TransformBullet::init()
{
	_textureBullet.setName("JafarBullet.png");
	_textureBullet.setSrcFile("Resources/Boss/Flame.png");
	Graphics::getInstance()->loadTexture(_textureBullet);
}

void TransformBullet::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	const auto collisionWithWall = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"wall");
	const auto collisionWithGround = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "ground");


	if (collisionWithWall != _rigid->getCollidingBodies().end())
		_owner->getCurrentScene()->removeNode(this);

	if (collisionWithGround != _rigid->getCollidingBodies().end())
	{
		if (_scale == Vec2(-0.9, 0.9))
		{
			if (abs(_rigid->getVelocity().getX()) == 30 )
			{
				setVelocity(Vec2(_rigid->getVelocity().getX() - 100, 0));
			}
			if (abs(_owner->getPosition().getX() - _position.getX()) > 350 * 0.45)
			{
				if (abs(_rigid->getVelocity().getX()) == 130)
				{
					setVelocity(Vec2(_rigid->getVelocity().getX() - 25, 0));
				}
			}
		}
		else
		{
			if (abs(_rigid->getVelocity().getX()) == 30)
			{
				setVelocity(Vec2(_rigid->getVelocity().getX() + 100, 0));
			}
			if (abs(_owner->getPosition().getX() - _position.getX()) > 350 * 0.45)
			{
				if (abs(_rigid->getVelocity().getX()) == 130)
				{
					setVelocity(Vec2(_rigid->getVelocity().getX() + 25, 0));
				}
			}
		}
		_rigid->setGravityScale(0);
	}
}

void TransformBullet::release()
{
	delete _rigid;
	delete this;
}

void TransformBullet::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.04;

	Graphics::getInstance()->drawSprite(_textureBullet, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureBullet, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
			rect, 2);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size())
			_animationIndex = 0;
	}
}

Texture TransformBullet::getTexture() const
{
	return _textureBullet;
}

void TransformBullet::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool TransformBullet::isCollision() const
{
	return _isCollision;
}

void TransformBullet::setActionName(const string actionName)
{
	_actionName = actionName;
}

string TransformBullet::getActionName() const
{
	return _actionName;
}

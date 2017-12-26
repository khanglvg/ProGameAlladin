#include "AppleToThrow.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/Scene.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"

US_NS_JK

AppleToThrow::AppleToThrow(GameObject* owner, const Vec2 & position, const Size & size):GameObject(position,size, APPLES)
{
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(0.1);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("appletothrow");

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/AppleToThrow.xml");

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
	setActionName("AppleToThrow");
}

AppleToThrow::~AppleToThrow()
{
}

void AppleToThrow::init()
{
	_textureApple.setName("AppleToThrow.png");
	_textureApple.setSrcFile("Resources/ala.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void AppleToThrow::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	const auto collisionWithEnemy = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"enemy");
	const auto collisionWithWall = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"wall");
	const auto collisionWithGround = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"ground");
	const auto collisionWithPlatform = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"platform");
	const auto collisionWithJafar = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"jafar");


	if (collisionWithEnemy != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (collisionWithWall != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (collisionWithGround != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (collisionWithPlatform != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else
		_isCollision = false;

	if (_actionName == "Apple-Explosion" && _animationIndex == 4)
	{
		_owner->getCurrentScene()->removeNode(this);
	}
	else if (_actionName == "Apple-Explosion-Boss" && _animationIndex == 18)
	{
		_owner->getCurrentScene()->removeNode(this);
	}

	if(_isCollision)
	{
		if (_actionName != "Apple-Explosion")
		{
			_rigid->setActive(false);
			_rigid->setGravityScale(0);
			setVelocity(Vec2(0,0));
			_actionName = "Apple-Explosion";
			_animationIndex = 0;
		}
	}
	else if (collisionWithJafar != _rigid->getCollidingBodies().end())
	{
		if (_actionName != "Apple-Explosion-Boss")
		{
			_rigid->setActive(false);
			_rigid->setGravityScale(0);
			setScale(Vec2(1.2,1.2));
			setVelocity(Vec2(0, 0));
			_actionName = "Apple-Explosion-Boss";
			_animationIndex = 0;
			_textureApple.setSrcFile("Resources/Items/Items-Explosion.png");
			Graphics::getInstance()->loadTexture(_textureApple);
		}
	}

	//if(_isCollision)
	//{
	//	//getCurrentScene()->removeNode(this);
	//	_owner->getCurrentScene()->removeNode(this);
	//}
}

void AppleToThrow::release()
{
	delete _rigid;
	delete this;
}

void AppleToThrow::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.01;

	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
			rect, 2);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size())
		{
			_animationIndex = 0;
			_isDone = true;
		}
	}
}

Texture AppleToThrow::getTexture() const
{
	return _textureApple;
}

void AppleToThrow::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool AppleToThrow::isCollision() const
{
	return _isCollision;
}

void AppleToThrow::setActionName(const string actionName)
{
	_actionName = actionName;
}

string AppleToThrow::getActionName() const
{
	return _actionName;
}

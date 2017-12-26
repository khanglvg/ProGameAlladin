#include "PotToThrow.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/Scene.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"

US_NS_JK

PotToThrow::PotToThrow(GameObject* owner, const Vec2 & position, const Size & size):GameObject(position,size, APPLES)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.001);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setCurrentScene(owner->getCurrentScene());
	setScale(Vec2(1, 1));
	_rigid->setTag("pottothrow");

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Enemies/Enemies.xml");

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
	setActionName("WallEnemy-Bullet");
}

PotToThrow::~PotToThrow()
{
}

void PotToThrow::init()
{
	_texturePot.setName("PotToThrow.png");
	_texturePot.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_texturePot);
}

void PotToThrow::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	const auto collisionWithAladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"aladdin");
	const auto collisionWithEnemy = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "enemy");
	const auto collisionWithGround = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"ground");
	const auto collisionWithPlatform = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"platform");
	auto const aladdinWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdinknife");

	if (collisionWithEnemy != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (collisionWithGround != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (collisionWithPlatform != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else
		_isCollision = false;

	if (collisionWithAladdin != _rigid->getCollidingBodies().end() || collisionWithEnemy != _rigid->getCollidingBodies().end())
	{
		//_owner->getCurrentScene()->removeNode(this);
	}
	else if (_actionName == "WallEnemy-BulletBroken" && _animationIndex == 7)
	{
		getCurrentScene()->removeNode(this);
	}
	else if (_actionName == "Enemy-Explosion" && _animationIndex == 9)
	{
		getCurrentScene()->removeNode(this);
	}

	if (collisionWithGround != _rigid->getCollidingBodies().end() || collisionWithPlatform != _rigid->getCollidingBodies().end())
	{
		if (_actionName != "WallEnemy-BulletBroken")
		{
			_rigid->setActive(false);
			_rigid->setGravityScale(0);
			setVelocity(Vec2(0,0));
			_actionName = "WallEnemy-BulletBroken";
			_animationIndex = 0;
		}
	}

	if (aladdinWeapon != _rigid->getCollidingBodies().end() && _actionName != "Enemy-Explosion")
	{
		_rigid->setActive(false);
		_rigid->setGravityScale(0);
		setVelocity(Vec2(0, 0));
		_actionName = "Enemy-Explosion";
		_texturePot.setSrcFile("Resources/Enemies/enemy_explosion_strip10_89_114.png");
		Graphics::getInstance()->loadTexture(_texturePot);
		setScale(Vec2(0.5, 0.5));
		_animationIndex = 0;
	}

	//if(_isCollision)
	//{
	//	//getCurrentScene()->removeNode(this);
	//	_owner->getCurrentScene()->removeNode(this);
	//}
}

void PotToThrow::release()
{
	delete _rigid;
	delete this;
}

void PotToThrow::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.01;

	if (_actionName == "Enemy-Explosion")
	{
		expect = 0.03;
	}

	Graphics::getInstance()->drawSprite(_texturePot, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_texturePot, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
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

Texture PotToThrow::getTexture() const
{
	return _texturePot;
}

void PotToThrow::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool PotToThrow::isCollision() const
{
	return _isCollision;
}

void PotToThrow::setActionName(const string actionName)
{
	_actionName = actionName;
}

string PotToThrow::getActionName() const
{
	return _actionName;
}

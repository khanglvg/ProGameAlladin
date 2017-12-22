#include "JafarBullet.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/Scene.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"

US_NS_JK

JafarBullet::JafarBullet(GameObject* owner, const Vec2 & position, const Size & size, GameObject* target):GameObject(position,size, APPLES)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.001);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("jafarbullet");

	_target = target;

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Boss/JafarBullet.xml");

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
	setActionName("Bullet");
	_targetPosition = Vec2(_target->getPosition().getX(), _target->getPosition().getY() - _target->getRect().getHeight() / 2);
	_distanceToAladdin = _targetPosition - _position;
	setVelocity(Vec2((_distanceToAladdin.getX() / 0.2) * 6, (_distanceToAladdin.getY() / 0.2) * 6));
}

JafarBullet::~JafarBullet()
{
}

void JafarBullet::init()
{
	_textureBullet.setName("JafarBullet.png");
	_textureBullet.setSrcFile("Resources/Boss/Jafar-Bullet.png");
	Graphics::getInstance()->loadTexture(_textureBullet);
}

void JafarBullet::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	_targetPosition = Vec2(_target->getPosition().getX(), _target->getPosition().getY() - _target->getRect().getHeight() / 2);
	_distanceToAladdin = _targetPosition - _position;

	const auto collisionWithAladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"aladdin");


	if (collisionWithAladdin != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else
		_isCollision = false;

	if (_actionName == "Bullet-Explosion" && _animationIndex == 3)
	{
		_owner->getCurrentScene()->removeNode(this);
	}

	if(_isCollision)
	{
		if (_actionName != "Bullet-Explosion")
		{
			setVelocity(Vec2(0,0));
			_actionName = "Bullet-Explosion";
			_animationIndex = 0;
		}
	}

	//if(_isCollision)
	//{
	//	//getCurrentScene()->removeNode(this);
	//	_owner->getCurrentScene()->removeNode(this);
	//}

	setVelocity(Vec2((_distanceToAladdin.getX() / 0.2) * 6, (_distanceToAladdin.getY() / 0.2) * 6));
}

void JafarBullet::release()
{
	delete _rigid;
	delete this;
}

void JafarBullet::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.01;

	Graphics::getInstance()->drawSprite(_textureBullet, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureBullet, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
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

Texture JafarBullet::getTexture() const
{
	return _textureBullet;
}

void JafarBullet::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool JafarBullet::isCollision() const
{
	return _isCollision;
}

void JafarBullet::setActionName(const string actionName)
{
	_actionName = actionName;
}

string JafarBullet::getActionName() const
{
	return _actionName;
}

Vec2 JafarBullet::getDistanceToAladdin() const
{
	return _distanceToAladdin;
}

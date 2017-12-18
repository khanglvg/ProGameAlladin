#include "KnifeToThrow.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"
US_NS_JK


KnifeToThrow::KnifeToThrow(GameObject* owner,const Vec2 & position, const Size & size) :GameObject(position, size, APPLES)
{
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(0.1);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(0.7);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("knifetothrow");

	_owner = owner;
	_isCollision = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Enemies/KnifeToThrow.xml");

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
	setActionName("KnifeToThrow");
}

KnifeToThrow::~KnifeToThrow()
{
}

void KnifeToThrow::init()
{
	_textureKnife.setName("KnifeToThrow.png");
	_textureKnife.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureKnife);
}

void KnifeToThrow::update()
{
	this->_position = _rigid->getPosition() - _rigid->getOffset();

	const auto aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");
	const auto ground = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "ground");
	const auto wall = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "wall");
	const auto platform = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "platform");

	if (aladdin != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (ground != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (wall != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else if (platform != _rigid->getCollidingBodies().end())
		_isCollision = true;
	else
		_isCollision = false;

	if (aladdin != _rigid->getCollidingBodies().end())
	{
		_owner->getCurrentScene()->removeNode(this);
	}
	else if (_actionName == "Knife-Explosion" && _animationIndex == 2)
	{
		_owner->getCurrentScene()->removeNode(this);
	}

	if (ground != _rigid->getCollidingBodies().end() || wall != _rigid->getCollidingBodies().end() || platform != _rigid->getCollidingBodies().end())
	{
		if (_actionName != "Knife-Explosion")
		{
			setVelocity(Vec2(0,0));
			_actionName = "Knife-Explosion";
			_textureKnife.setSrcFile("Resources/Items/Items-Explosion.png");
			Graphics::getInstance()->loadTexture(_textureKnife);
			_animationIndex = 0;
		}
	}

	//if (_isCollision)
	//{
	//	_owner->getCurrentScene()->removeNode(this);
	//}
}

void KnifeToThrow::release()
{
	delete _rigid;
	delete this;
}

void KnifeToThrow::render()
{

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.01;

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
		if (_animationIndex == _animations[_actionName].size())
		{
			_animationIndex = 0;
			_isDone = true;
		}
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

void KnifeToThrow::setGravityScale(const float & gravity)
{
	_rigid->setGravityScale(gravity);
}
void KnifeToThrow::setActionName(const string actionName)
{
	_actionName = actionName;
}

string KnifeToThrow::getActionName() const
{
	return _actionName;
}
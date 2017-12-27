#include "Camel.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Aladdin.h"
#include "../../Weapons/CamelBullet.h"

US_NS_JK

Camel::Camel()
{
	
}

Camel::Camel(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player):GameObject(position, size, tag)
{
	setScale(Vec2(1, 1));
	_rigid->setTag("camel");
	_player = player;
	_isShoot = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/Camel.xml");

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

	_actionName = "Camel-Idle";
}


Camel::~Camel()
{
}

void Camel::init()
{
	_textureCamel.setName("Camel.jpg");
	_textureCamel.setSrcFile("Resources/Items/Genesis 32X SCD - Aladdin - Camel.png");
	Graphics::getInstance()->loadTexture(_textureCamel);

	_textureCamelRigid.setName("CamelRigid.png");
	_textureCamelRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureCamelRigid);
}

void Camel::release()
{
	delete this;
}

void Camel::update()
{
	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (_player->getRigidBody()->getPosition().getY()-7 < _rigid->getPosition().getY() - _rigid->getSize().getHeight())
	{
		_rigid->setActive(true);
	}
	else
	{
		if (aladdin == _rigid->getCollidingBodies().end())
		{
			_rigid->setActive(false);
		}
	}

	if (aladdin != _rigid->getCollidingBodies().end())
	{
		if (_actionName != "Camel")
		{
			_actionName = "Camel";
			_animationIndex = 0;
		}
	}
	else
	{
		if (_actionName == "Camel" && _animationIndex == 8)
		{
			_actionName = "Camel-Idle";
			_animationIndex = 0;
		}
	}

	if (_actionName == "Camel" && _animationIndex == 5)
	{
		if (!_isShoot)
		{
			auto bullet = new CamelBullet(this, Vec2(_rigid->getPosition().getX() + 90, _rigid->getPosition().getY()), Size(18, 15));
			bullet->setGravityScale(0);
			bullet->getRigidBody()->setVelocity(Vec2(150, 0));
			getCurrentScene()->addNode(bullet);
			_isShoot = true;
		}
	}
	else
	{
		_isShoot = false;
	}
}

void Camel::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.02;
	
	auto origin = Vec2(0.3f, 1.0f);

	Graphics::getInstance()->drawSprite(_textureCamelRigid, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 3);
	Graphics::getInstance()->drawSprite(_textureCamel, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 3);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureCamel, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 3);
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

void Camel::setActionName(string actionName)
{
	_actionName = actionName;
}

string Camel::getActionName() const
{
	return _actionName;
}

Rect Camel::getRect()
{
	auto width = _animations[_actionName][_animationIndex].getWidth();
	auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}

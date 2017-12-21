#include "Jafar.h"
#include "../../Framework/Graphics.h"
#include "../../../Framework/GameManager.h"
US_NS_JK

Jafar::Jafar()
{
}

Jafar::Jafar(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* target)
	:Enemy(position, size, tag, target)
{
	_attackRange = 80;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 90;
	setScale(Vec2(1, 1));

	_health = 5;

	_rigid->setTag("jafar");
	_isCollisionWithApple = false;
	_isTransform = false;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Boss/Jafar.xml");

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

	//_actionName = "Idle";
	_actionName = "Attack";
}
Jafar::~Jafar()
{
}

void Jafar::init()
{
	_textureJafar.setSrcFile("Resources/Boss/jafar.png");
	//_textureJafar.setSrcFile("Resources/red_rect.png");
	_textureJafar.setName("Jafar");
	Graphics::getInstance()->loadTexture(_textureJafar);
}

void Jafar::release()
{
}

void Jafar::update()
{
	if(_target->getRigidPosition().getX() < _rigid->getPosition().getX())
	{
		setScale(Vec2(-1, 1));
	}
	else
	{
		setScale(Vec2(1, 1));
	}

	_position = _rigid->getPosition() - _rigid->getOffset();


	auto const apple = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");

	if(apple != _rigid->getCollidingBodies().end())
	{
		_isCollisionWithApple = true;
	}
	else
	{
		_isCollisionWithApple = false;
	}



	if(_isCollisionWithApple)
	{
		if (_health > 0)
		{
			_health--;
			_isCollisionWithApple = false;
		}
	}


	if (_health <= (21-8))
	{
		// bien hinh
		_isTransform = true;
	}
	else
	{
		_isTransform = false;
	}

	if(_health == 0)
	{
		OutputDebugString("dieeeeeeeeeeeeeeeeeeeeeeeeeee");
	}

//	_rigid->getCollidingBodies().clear();
}

void Jafar::render()
{
	if (_isTransform)
	{
			
	}


	const auto rect = _animations[_actionName][_animationIndex];
	const auto expect = 0.05;

	const auto origin = Vec2(0.5f, 1.0f);

	Graphics::getInstance()->drawSprite(_textureJafar, origin, getTransformMatrix(), Color(255, 255, 255, 255),
		rect, 2);

	if (_index <= expect)
	{
		Graphics::getInstance()->drawSprite(_textureJafar, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
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

bool Jafar::isTransform() const
{
	return _isTransform;
}

Rect Jafar::getRect()
{
	return Rect(0, 0, 0, 0);
}

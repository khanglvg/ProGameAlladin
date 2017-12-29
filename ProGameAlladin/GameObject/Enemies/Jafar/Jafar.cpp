#include "Jafar.h"
#include "../../Framework/Graphics.h"
#include "../../../Framework/GameManager.h"
#include "JafarIdleState.h"
#include "JafarAttackState.h"
#include "Transform/TransformIdleState.h"
#include "Transform/TransformAttackState.h"
#include "../../Weapons/Fire.h"

US_NS_JK

Jafar::Jafar()
{
}

Jafar::Jafar(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* target)
	:Enemy(position, size, tag, target)
{
	_attackRange = 280;
	setScale(Vec2(1, 1));

	_health = 21;
	_position = _rigid->getPosition();
	_position.setY(_rigid->getPosition().getY() - _rigid->getOffset().getY());

	_rigid->setTag("jafar");
	_isCollisionWithApple = false;
	_isTransform = false;
	_isChecked = false;
	_isDeHeal = false;
	_isDie = false;

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

#pragma region READ - XML
	const auto resultTransform = doc.load_file("Resources/Boss/Transform.xml");

	if (resultTransform)
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
			_transformAnimations.emplace(name, rects);
		}
	}
#pragma endregion 

	_currentState = new JafarIdleState(this);
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

	_textureTransform.setSrcFile("Resources/Boss/transform.png");
	//_textureJafar.setSrcFile("Resources/red_rect.png");
	_textureTransform.setName("Jafar");
	Graphics::getInstance()->loadTexture(_textureTransform);
}

void Jafar::release()
{
}

void Jafar::update()
{
	//_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	//_rigid->setOffset(Vec2(_rigid->getSize().getWidth() / 2, -_rigid->getSize().getHeight() / 2));
	//_position = _rigid->getPosition() - _rigid->getOffset();

	_currentState->onUpdate();

	if(_target->getRigidPosition().getX() < _rigid->getPosition().getX())
	{
		setScale(Vec2(-1, 1));
	}
	else
	{
		setScale(Vec2(1, 1));
	}

	_position = _rigid->getPosition();
	_position.setY(_rigid->getPosition().getY() - _rigid->getOffset().getY());


	const auto apple = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");

	if(apple != _rigid->getCollidingBodies().end())
	{
		_isCollisionWithApple = true;
	}
	else
	{
		_isCollisionWithApple = false;
		_isChecked = false;
	}


	if(_isCollisionWithApple && _health > 0 && !_isChecked)
	{
		_isDeHeal = false;
	}



	if(_isCollisionWithApple && !_isDeHeal)
	{
			_health--;
			_isChecked = true;
			_isDeHeal = true;
			OutputDebugString(std::to_string(_health).c_str());
	}


	if (!_isTransform && _health <= (21 - 8))
	{
		// bien hinh
		_isTransform = true;
		_currentState->onExit();
		delete _currentState;
		_currentState = new TransformIdleState(this); 
		_animationIndex = 0;

		//Flame
		auto flameCenter = new Fire(Vec2(_rigid->getPosition().getX() + 5, _rigid->getPosition().getY() + 2), Size(30, 56));
		flameCenter->getRigidBody()->setActive(false);
		flameCenter->setLayer(1);
		flameCenter->getRigidBody()->setGravityScale(0);
		flameCenter->setCurrentScene(this->getCurrentScene());
		this->getCurrentScene()->addNode(flameCenter);
		//Flame
		auto flameLeft = new Fire(Vec2(_rigid->getPosition().getX() - 10, _rigid->getPosition().getY() + 2), Size(30, 56));
		flameLeft->getRigidBody()->setActive(false);
		flameLeft->getRigidBody()->setGravityScale(0);
		flameLeft->setCurrentScene(this->getCurrentScene());
		this->getCurrentScene()->addNode(flameLeft);
		//Flame
		auto flameRight = new Fire(Vec2(_rigid->getPosition().getX() + 25, _rigid->getPosition().getY() + 2), Size(30, 56));
		flameRight->getRigidBody()->setActive(false);
		flameRight->setLayer(1);
		flameRight->getRigidBody()->setGravityScale(0);
		flameRight->setCurrentScene(this->getCurrentScene());
		this->getCurrentScene()->addNode(flameRight);
	}

	if(_health == 0)
	{
		_rigid->setActive(false);
		_isDie = true;
		OutputDebugString("dieeeeeeeeeeeeeeeeeeeeeeeeeee");
	}

//	_rigid->getCollidingBodies().clear();

	Enemy::update();

	EnemyState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_animationIndex = 0;
	}
}

void Jafar::render()
{
	if (_isTransform)
	{
		if (!_isDie)
		{
			const auto rect = _transformAnimations[_actionName][_animationIndex];
			const auto expect = 0.07;

			auto origin = Vec2(0.5f, 1.0f);

			if (_animationIndex >=2 && _animationIndex <=8)
			{
				origin = Vec2(0.8f, 1.0f);
			}

			Graphics::getInstance()->drawSprite(_textureTransform, origin, getTransformMatrix(), Color(255, 255, 255, 255),
				rect, 2);

			if (_index <= expect)
			{
				Graphics::getInstance()->drawSprite(_textureTransform, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
				_index += GameManager::getInstance()->getDeltaTime();
			}
			else
			{
				_index = 0;
				_animationIndex++;
				if (_animationIndex == _transformAnimations[_actionName].size())
					_animationIndex = 0;

			}
		}
		else
		{
			_animationIndex = 1;
		}
	}
	else
	{
		const auto rect = _animations[_actionName][_animationIndex];
		const auto expect = 0.05;

		auto origin = Vec2(0.5f, 1.0f);

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
}

bool Jafar::isTransform() const
{
	return _isTransform;
}

int Jafar::getHealth() const
{
	return _health;
}

Rect Jafar::getRect()
{
	float width = 0;
	float height = 0;

	if (!_isTransform)
	{
		width = _animations[_actionName][_animationIndex].getWidth();
		height = _animations[_actionName][_animationIndex].getHeight();
	}
	else
	{
		width = _transformAnimations[_actionName][_animationIndex].getWidth();
		height = _transformAnimations[_actionName][_animationIndex].getHeight();
	}

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}

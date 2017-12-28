#include "BigEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "../../../Framework/GameMap.h"
#include "../EnemyExplosionState.h"

US_NS_JK

BigEnemy::BigEnemy()
{
}

BigEnemy::BigEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_health = 20;
	_attackRange = 80;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 90;
	setScale(Vec2(1, 1));
	_rigid->setSize(size);
	_isAttacked = false;
	_currentState = new BigEnemyIdleState(this);
}

BigEnemy::~BigEnemy()
{
}

void BigEnemy::init()
{
	_textureEnemy.setName("BigEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureBigEnemy.setName("BigEnemyRigid.png");
	_textureBigEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureBigEnemy);
}

void BigEnemy::release()
{
	delete _rigid;
}

void BigEnemy::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();


	auto const aladdinWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdinknife");
	auto const appleWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");
	auto const fireground = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "fireground");

	if (aladdinWeapon != _rigid->getCollidingBodies().end() || appleWeapon != _rigid->getCollidingBodies().end())
	{
		if (!_isAttacked)
		{
			if (aladdinWeapon != _rigid->getCollidingBodies().end())
				_health -= 10;
			else
				_health -= 8;
			_isAttacked = true;
			//OutputDebugString(std::to_string(_health).c_str());
		}
	}
	else
	{
		_isAttacked = false;
	}

	if (fireground != _rigid->getCollidingBodies().end())
	{
		_isInFire = true;
	}
	else
		_isInFire = false;

	if (_actionName == "Enemy-Explosion" && _animationIndex == 9)
	{
		_map->deleteEnemy(this);
	}

	_currentState->onUpdate();

	if (_currentState->isChange())
	{
		_animationIndex = 0;
		_isAnimationDone = false;
	}

	Enemy::update();

	const auto newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_animationIndex = 0;
		_isAnimationDone = false;
	}


	if (_health <= 0 && _actionName != "Enemy-Explosion")
	{
		_rigid->setGravityScale(0);
		setVelocity(Vec2(0, 0));
		_currentState->onExit();
		delete _currentState;
		_currentState = new EnemyExplosionState(this);
		_animationIndex = 0;
	}
}

void BigEnemy::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.05;

	if (_actionName == "Enemy-Explosion")
	{
		expect = 0.03;
	}

	auto origin = Vec2(0.3f, 1.0f);

	if (_actionName == "BigEnemy-AttackHigh" && _animationIndex >2 && _animationIndex <5)
	{
		origin = Vec2(0.8f, 1.0f);
	}

	if (_actionName == "BigEnemy-AttackLow")
	{
		origin = Vec2(0.8f, 1.0f);
	}

	if (_actionName == "BigEnemy-Defiant")
	{
		origin = Vec2(0.8f, 1.0f);
	}

	Graphics::getInstance()->drawSprite(_textureBigEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 3);
	Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 3);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 3);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size() && _actionName == "BigEnemy-Defiant") 
		{
			_animationIndex = 2;
		}
		else if (_animationIndex == _animations[_actionName].size() && _actionName == "BigEnemy-AttackLow")
		{
			_isAnimationDone = true;
			_animationIndex = 3;
		}
		else if (_animationIndex == _animations[_actionName].size())
		{
			_isAnimationDone = true;
			_animationIndex = 0;
		}
			
	}
}

Rect BigEnemy::getRect()
{
	const auto width = _animations[_actionName][_animationIndex].getWidth();
	const auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}

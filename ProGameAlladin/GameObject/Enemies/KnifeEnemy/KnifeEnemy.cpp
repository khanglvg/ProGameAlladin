#include "KnifeEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "../EnemyExplosionState.h"
#include "../../../Framework/GameMap.h"

US_NS_JK

KnifeEnemy::KnifeEnemy()
{
}

KnifeEnemy::KnifeEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_health = 10;
	_viewRange = 220;
	_attackRange = 140;
	_isAttacked = false;
	_currentState = new KnifeEnemyIdleState(this);
}

KnifeEnemy::~KnifeEnemy()
{
}

void KnifeEnemy::init()
{
	_textureEnemy.setName("KnifeEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureKnifeEnemy.setName("KnifeEnemyRigid.png");
	_textureKnifeEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureKnifeEnemy);
}

void KnifeEnemy::release()
{
	delete _rigid;
}

void KnifeEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	_position = _rigid->getPosition() - _rigid->getOffset();

	auto const aladdinWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdinknife");
	auto const appleWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");
	auto const itemkill = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "itemkill");

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

	if (_actionName == "Enemy-Explosion" && _animationIndex == 9)
	{
		_map->deleteEnemy(this);
	}

	_currentState->onUpdate();

	Enemy::update();

	EnemyState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
	}

	if ((_health <= 0 || itemkill != _rigid->getCollidingBodies().end()) && _actionName != "Enemy-Explosion")
	{
		_rigid->setGravityScale(0);
		setVelocity(Vec2(0, 0));
		_currentState = new EnemyExplosionState(this);
		_animationIndex = 0;
	}
}

void KnifeEnemy::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.04;


	if (_actionName == "Enemy-Explosion")
	{
		expect = 0.03;
	}

	auto origin = Vec2(0.4f, 1.0f);

	//if (_actionName == "KnifeEnemy-Idle" && _animationIndex == 5)
	//{
	//	origin = Vec2(0.9f, 1.0f);
	//}
	if (_actionName == "KnifeEnemy-Idle" && _animationIndex >6 && _animationIndex <11)
	{
		origin = Vec2(0.2f, 1.0f);
	}


	//Graphics::getInstance()->drawSprite(_textureKnifeEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 3);
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
		if (_animationIndex == _animations[_actionName].size())
			_animationIndex = 0;

	}
}

Rect KnifeEnemy::getRect()
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

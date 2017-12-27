#include "WallEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "../EnemyExplosionState.h"
#include "../../../Framework/GameMap.h"

US_NS_JK

WallEnemy::WallEnemy()
{


}

WallEnemy::WallEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player) :Enemy(position, size, tag, player)
{
	_health = 10;
	_viewRange = 30;
	setScale(Vec2(1, 1));
	_isAttacked = false;
	_currentState = new WallEnemyIdleState(this);
}


WallEnemy::~WallEnemy()
{
}

void WallEnemy::init()
{
	_textureEnemy.setName("WallEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureWallEnemy.setName("WallEnemyRigid.png");
	_textureWallEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureWallEnemy);
}

void WallEnemy::release()
{
	delete _rigid;
	delete this;
}

void WallEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	_position = _rigid->getPosition() - _rigid->getOffset();

	auto const aladdinWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdinknife");
	auto const appleWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");
	auto const itemkill = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "itemkill");

	if (aladdinWeapon != _rigid->getCollidingBodies().end() || appleWeapon != _rigid->getCollidingBodies().end())
	{
		if (_actionName == "WallEnemy-Attack" && _animationIndex < 8 && _animationIndex > 0)
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
		_animationIndex = 0;
	}

	if ((_health <= 0 || itemkill != _rigid->getCollidingBodies().end()) && _actionName != "Enemy-Explosion")
	{
		_rigid->setGravityScale(0);
		setVelocity(Vec2(0, 0));
		_currentState = new EnemyExplosionState(this);
		_animationIndex = 0;
	}
}

void WallEnemy::render()
{
	auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.05;
	if (_actionName == "WallEnemy-Idle")
	{
		rect = Rect(0, 0, 0, 0);
	}

	if (_actionName == "Enemy-Explosion")
	{
		expect = 0.03;
	}
	

	auto origin = Vec2(0.3f, 1.0f);


	//Graphics::getInstance()->drawSprite(_textureWallEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
	Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
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

	Rect WallEnemy::getRect()
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

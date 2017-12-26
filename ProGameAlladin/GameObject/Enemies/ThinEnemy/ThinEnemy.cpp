#include "ThinEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"
#include "../EnemyExplosionState.h"
#include "../../../Framework/GameMap.h"

US_NS_JK

ThinEnemy::ThinEnemy()
{
	//_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	////setPosition(_rigid->getPosition() - _rigid->getOffset());
	//setPosition(_startPosition);
	//setScale(Vec2(1, 1));

	//_currentState = new ThinEnemyIdleState(this);
}

ThinEnemy::ThinEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player) 
:Enemy(position, size, tag, player)
{
	_attackRange = 80;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 80;
	setScale(Vec2(1, 1));

	_currentState = new ThinEnemyIdleState(this);
	_isCollisionWithAladdin = false;
	_isAttacked = false;
}

ThinEnemy::~ThinEnemy()
{
}

void ThinEnemy::init()
{
	_textureEnemy.setName("ThinEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);


	_textureThinEnemy.setName("ThinEnemyRigid.png");
	_textureThinEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureThinEnemy);
}

void ThinEnemy::release()
{
	delete _rigid;
	delete this;
}

void ThinEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth()*1.6+_rigid->getOffset().getX()*2, getRect().getHeight()));
	_position = _rigid->getPosition() -_rigid->getOffset();

	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");
	auto const aladdinWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdinknife");
	auto const appleWeapon = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "appletothrow");

	if(aladdin == _rigid->getCollidingBodies().end())
	{
		_isCollisionWithAladdin =  false;
	}
	else
	{
		_isCollisionWithAladdin = true;
	}

	if (aladdinWeapon != _rigid->getCollidingBodies().end() || appleWeapon != _rigid->getCollidingBodies().end())
	{
		if (!_isAttacked)
		{
			if (aladdinWeapon != _rigid->getCollidingBodies().end())
				_health-= 10;
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
		_animationIndex = 0;
	}

	if (_health <= 0 && _actionName != "Enemy-Explosion")
	{
		_rigid->setGravityScale(0);
		setVelocity(Vec2(0, 0));
		_currentState = new EnemyExplosionState(this);
		_animationIndex = 0;
	}
}

void ThinEnemy::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.05;

	if (_actionName == "Enemy-Explosion")
	{
		expect = 0.03;
	}
	
	auto origin = Vec2(0.3f, 1.0f);

	if (_actionName == "ThinEnemy-Attack" && _animationIndex >1 && _animationIndex <5)
	{
		origin = Vec2(0.8f, 1.0f);
	}


	Graphics::getInstance()->drawSprite(_textureThinEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 3);
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

Rect ThinEnemy::getRect()
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


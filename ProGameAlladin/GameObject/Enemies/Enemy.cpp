#include "Enemy.h"
#include "../../Framework/Graphics.h"

US_NS_JK

Enemy::Enemy()
{

}

Enemy::Enemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* target) :GameObject(position, size, tag)
{
	_rigid->setDensity(0.001);
	_startPosition = position;
	_target = target;
	_distanceToTarget = _target->getPosition() - _position;

	_footPosY = 0;

	_health = 2;
	_damage = 5;
	_speed = 10;
	_boundaryLeft = _startPosition.x - 50;
	_boundaryRight = _startPosition.x + 50;
	_viewRange = 250;
	_attackRange = 100;
	_isRight = false;
	_allowMoveLeft = _allowMoveRight = true;

	_rigid->setTag("enemy");

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
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
}

void Enemy::release()
{
	delete this;
}

void Enemy::update()
{
	/*handle move action here*/
	_distanceToTarget = _target->getPosition() - _position;

	//face to left or right
	if (_distanceToTarget.x > 0)
		_isRight = true;
	else if (_distanceToTarget.x < 0)
		_isRight = false;

	_allowMoveLeft = (_position.x > _boundaryLeft) ? true : false;

	_allowMoveRight = (_position.x < _boundaryRight) ? true : false;


	
	//move
	//if (isTargetInViewRange() && !isTargetInAttackRange())
	//{
	//	if (_distanceToTarget.x > 0 && _allowMoveRight)
	//	{
	//		//move right
	//		_velocity.x = _speed;
	//	}
	//	else if (_distanceToTarget.x < 0 && _allowMoveLeft)
	//	{
	//		//move left
	//		_velocity.x = -1 * _speed;
	//	}
	//}
	//else
	//{
	//	//v=0
	//	_velocity.x = 0;
	//}

	//fix foot posY
	//_position.y = _footPosY - getHeight() / 2;
}

void Enemy::render()
{

}

void Enemy::setActionName(const string actionName)
{
	_actionName = actionName;
}

string Enemy::getActionName() const
{
	return _actionName;
}

Vec2 Enemy::getVelocity() const
{
	return _rigid->getVelocity();
}

void Enemy::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool Enemy::isTargetInViewRange()
{
	if (abs(_distanceToTarget.x) <= _viewRange && _distanceToTarget.y < 200)
		return true;
	return false;
}

bool Enemy::isTargetInAttackRange()
{
	if (abs(_distanceToTarget.x) <= _attackRange && _distanceToTarget.y < _target->getSize().getHeight())
		return true;
	return false;
}

int Enemy::getHealth()
{
	return _health;
}

void Enemy::setHealth(int newHealth)
{
	_health = newHealth;
}

int Enemy::getDamage()
{
	return _damage;
}

void Enemy::setDamage(int newDamage)
{
	_damage = newDamage;
}

int Enemy::getViewRange()
{
	return _viewRange;
}

void Enemy::setViewRange(int viewRange)
{
	_viewRange = viewRange;
}

int Enemy::getAttackRange()
{
	return _attackRange;
}

void Enemy::setAttackRange(int attackRange)
{
	_attackRange = attackRange;
}

bool Enemy::isRight()
{
	return _isRight;
}

void Enemy::setIsRight(bool right)
{
	_isRight = right;
}

bool Enemy::isAllowMoveLeft()
{
	return _allowMoveLeft;
}

bool Enemy::isAllowMoveRight()
{
	return _allowMoveRight;
}

void Enemy::allowMoveLeft(const bool allow)
{
	_allowMoveLeft = allow;
}

void Enemy::allowMoveRight(const bool allow)
{
	_allowMoveRight = allow;
}

void Enemy::setTexture(const string & srcFile)
{
	_textureEnemy.setSrcFile(srcFile);
	Graphics::getInstance()->loadTexture(_textureEnemy);
}

bool Enemy::isAnimationDone()
{
	return _isAnimationDone;
}

int Enemy::getIndex()
{
	return _animationIndex;
}

void Enemy::setGameMap(GameMap * map)
{
	_map = map;
}

GameObject * Enemy::getTarget() const
{
	return _target;
}

Rect Enemy::getRect()
{
	return Rect();
}

void Enemy::setFootPosY()
{
	if (_footPosY == 0)
		_footPosY = _position.y + getSize().getHeight() / 2;
}


bool Enemy::getIsCollisionWithAladdin() const
{
	return _isCollisionWithAladdin;
}
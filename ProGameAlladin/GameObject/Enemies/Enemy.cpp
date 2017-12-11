#include "Enemy.h"
US_NS_JK

Enemy::Enemy()
{
	//_startPosition = Vec2(SCREEN_WIDTH /3, SCREEN_HEIGHT - 50);
	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	////setPosition(_rigid->getPosition() - _rigid->getOffset());
	//setPosition(_startPosition);
	//setScale(Vec2(-1, 1));
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

Enemy::Enemy(GameObject * target) : GameObject(GameObject::GameObjectType::Enemies)
{
	_target = target;
	_distanceToTarget = _target->getPosition() - _position;

	_footPosY = 0;

	_health = 100;
	_damage = 5;
	_speed = 10;
	_viewRange = 200;
	_attackRange = 80;
	_isRight = false;
	_allowMoveLeft = _allowMoveRight = true;

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

	//move
	if (isTargetInViewRange() && !isTargetInAttackRange())
	{
		if (_distanceToTarget.x > 0 && _allowMoveRight)
		{
			//move right
			_velocity.x = _speed;
		}
		else if (_distanceToTarget.x < 0 && _allowMoveLeft)
		{
			//move left
			_velocity.x = -1 * _speed;
		}
	}
	else
	{
		//v=0
		_velocity.x = 0;
	}

	//fix foot posY
	//_position.y = _footPosY - getHeight() / 2;
}

void Enemy::render()
{

}

void Enemy::setActionName(string actionName)
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
	if (abs(_distanceToTarget.x) <= _viewRange || abs(_distanceToTarget.y) < getHeight())
		return true;
	return false;
}

bool Enemy::isTargetInAttackRange()
{
	if (abs(_distanceToTarget.x) <= _attackRange && abs(_distanceToTarget.y) < getHeight())
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

void Enemy::allowMoveLeft(bool allow)
{
	_allowMoveLeft = allow;
}

void Enemy::allowMoveRight(bool allow)
{
	_allowMoveRight = allow;
}

void Enemy::setFootPosY()
{
	if (_footPosY == 0)
		_footPosY = _position.y + getHeight() / 2;
}

#include "Weapon.h"
#include "../../Framework/Graphics.h"
US_NS_JK

Weapon::Weapon()
{
}

Weapon::Weapon(GameObject* owner, const Vec2& rigidPosition, const Size& rigidSize, const Vec2& attackRange, const string& tag): GameObject(rigidPosition,rigidSize)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.00000001);
	_owner = owner;
	_rigid->setTag(tag);
	_rigid->setActive(false);
	_attackRange = attackRange;
}

Weapon::~Weapon()
{
}

void Weapon::init()
{
	_textureRigid.setName("Weapon");
	_textureRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void Weapon::update()
{
	if (_owner->getRigidBody()->getTag() == "aladdin")
	{
		if (_owner->isOwnerRight())
		{
			_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() + (_rigid->getSize().getWidth() - _owner->getRigidBody()->getSize().getWidth()) + _attackRange.getX(), _owner->getRigidBody()->getPosition().getY() - _attackRange.getY()));
			_position = _rigid->getPosition() - _rigid->getOffset();
		}
		else
		{
			_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() - _attackRange.getX(), _owner->getRigidBody()->getPosition().getY() - _attackRange.getY()));
			_position = _rigid->getPosition() - _rigid->getOffset();
		}
	}


	if (_owner->getRigidBody()->getTag() == "enemy")
	{
		if (_owner->isOwnerRight())
		{
			_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() + _attackRange.getX() / 2 + 30, _owner->getRigidBody()->getPosition().getY() - _attackRange.getY()));
			_position = _rigid->getPosition() - _rigid->getOffset();
		}
		else
		{
			_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() - _attackRange.getX() / 2 - 30, _owner->getRigidBody()->getPosition().getY() - _attackRange.getY()));
			_position = _rigid->getPosition() - _rigid->getOffset();
		}
	}
	
	
}

void Weapon::render()
{
	/*if(_rigid->isActived())
	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
*/
}

GameObject* Weapon::getOwner() const
{
	return _owner;
}


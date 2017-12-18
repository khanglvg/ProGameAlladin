#include "Weapon.h"
#include "../Framework/Graphics.h"
US_NS_JK

Weapon::Weapon()
{
}

Weapon::Weapon(GameObject* owner, const Vec2& rigidPosition, const Size& rigidSize, const string& tag): GameObject(rigidPosition,rigidSize)
{
	_rigid->setBodyType(DYNAMIC);
	_owner = owner;
	_rigid->setTag(tag);
	_rigid->setActive(false);
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
	if(_owner->isOwnerRight())
	{
		_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() + 25, _owner->getRigidBody()->getPosition().getY()-12));
		_position = _rigid->getPosition() - _rigid->getOffset();
	}
	else
	{
		_rigid->setPosition(Vec2(_owner->getRigidBody()->getPosition().getX() - 40, _owner->getRigidBody()->getPosition().getY() - 12));
		_position = _rigid->getPosition() - _rigid->getOffset();
	}
	
}

void Weapon::render()
{
	if(_rigid->isActived())
	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);

}

GameObject* Weapon::getOwner() const
{
	return _owner;
}


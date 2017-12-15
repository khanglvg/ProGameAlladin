#include "GameObject.h"
#include "../Framework/Graphics.h"

US_NS_JK


GameObject::GameObject()
{
}

GameObject::GameObject(const Vec2 & position, const Size & size, const GameObjectType tag)
{
	_rigid = new RigidBody(position, Vec2(0, 0), STATIC, 1000, 0, 0, Vec2(0, 0), 0, Vec2(size.getWidth() / 2, -size.getHeight() / 2), size);
	setPosition(_rigid->getPosition() - _rigid->getOffset());
	_tag = tag;
	_isVisible = true;	
}


GameObject::~GameObject()
{
}

void GameObject::init()
{
	_textureRigid.setName("GameObjectRigid.png");
	_textureRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void GameObject::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();
}


void GameObject::render()
{
	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
}

void GameObject::release()
{
}

#pragma region GET-SET

GameObject::GameObjectType GameObject::getTag() const
{
	return _tag;
}

bool GameObject::isOwnerRight() const
{
	return _isOwnerRight;
}

void GameObject::setIsOwnerRight(const bool& isOwnerRight)
{
	_isOwnerRight = isOwnerRight;
}

bool GameObject::isVisible() const
{
	return _isVisible;
}

Size GameObject::getSize() const
{
	return _rigid->getSize();
}

Vec2 GameObject::getRigidPosition() const
{
	return _rigid->getPosition();
}

void GameObject::setSize(const Size& size)
{
	_rigid->setSize(size);
}

void GameObject::setRigidPosition(const Vec2& position)
{
	_rigid->setPosition(position);
}
void GameObject::setRigidTag(const string & rigidTag)
{
	_rigid->setTag(rigidTag);
}
string GameObject::getRigidTag() const
{
	return 	_rigid->getTag();
}

RigidBody* GameObject::getRigidBody() const
{
	return _rigid;
}
#pragma endregion 

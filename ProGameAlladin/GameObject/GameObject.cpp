#include "GameObject.h"

US_NS_JK

GameObject::GameObject(GameObjectType tag)
{
	_tag = tag;


	_position = Vec2(0, 0);
	_velocity = Vec2(0, 0);

	_isVisible = true;
}

GameObject::~GameObject()
{
}

int GameObject::getWidth()
{
	return _width;
}

void GameObject::setWidth(int width)
{
	_width = width;
}

int GameObject::getHeight()
{
	return _height;
}

void GameObject::setHeight(int height)
{
	_height = height;
}

GameObject::GameObjectType GameObject::getTag()
{
	return _tag;
}

bool GameObject::isVisible()
{
	return _isVisible;
}

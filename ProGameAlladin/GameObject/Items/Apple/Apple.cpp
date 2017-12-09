#include "Apple.h"
US_NS_JK

Apple::Apple()
{
	_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	setPosition(_startPosition);
	setScale(Vec2(1, 1));
}

Apple::Apple(GameObject * target) : GameObject(GameObject::GameObjectType::Apple)
{

}

Apple::~Apple()
{
}

void Apple::init()
{
	_textureApple.setName("Apple.jpg");
	_textureApple.setSrcFile("Resources/Items/Apple.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void Apple::release()
{
	delete this;
}

void Apple::update()
{
}

void Apple::render()
{
	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.0f, 0.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,11,12), 1);
}

Rect Apple::getRect()
{
	Rect rect;
	rect.setX(this->getPosition().getX());
	rect.setY(this->getPosition().getY());
	rect.setWidth(this->getWidth());
	rect.setHeight(this->getHeight());
	return rect;
}

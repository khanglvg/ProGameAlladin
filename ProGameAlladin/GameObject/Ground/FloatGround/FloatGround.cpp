#include "FloatGround.h"
US_NS_JK

FloatGround::FloatGround()
{
	_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	setPosition(_startPosition);
	setScale(Vec2(1, 1));
}

FloatGround::FloatGround(GameObject * target) : GameObject(GameObject::GameObjectType::Apple)
{

}

FloatGround::~FloatGround()
{
}

void FloatGround::init()
{
	_textureFloatGround.setName("FloatGround.jpg");
	_textureFloatGround.setSrcFile("Resources/Items/FloatGround.png");
	Graphics::getInstance()->loadTexture(_textureFloatGround);
}

void FloatGround::release()
{
	delete this;
}

void FloatGround::update()
{
}

void FloatGround::render()
{
	Graphics::getInstance()->drawSprite(_textureFloatGround, Vec2(0.0f, 0.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,33,14), 1);
}

Rect FloatGround::getRect()
{
	Rect rect;
	rect.setX(this->getPosition().getX());
	rect.setY(this->getPosition().getY());
	rect.setWidth(33);
	rect.setHeight(14);
	return rect;
}

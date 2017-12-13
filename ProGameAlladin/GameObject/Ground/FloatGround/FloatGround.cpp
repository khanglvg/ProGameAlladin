#include "FloatGround.h"
US_NS_JK

FloatGround::FloatGround()
{
	
}

FloatGround::FloatGround(const Vec2& position, const Size& size, const GameObjectType& tag) :GameObject(position, size, tag)
{
	setScale(Vec2(1, 1));
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
	Graphics::getInstance()->drawSprite(_textureFloatGround, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,getSize().getWidth(), getSize().getHeight()), 1);
}

Rect FloatGround::getRect()
{
	Rect rect;
	rect.setX(this->getPosition().getX());
	rect.setY(this->getPosition().getY());
	rect.setWidth(_rigid->getSize().getWidth());
	rect.setHeight(_rigid->getSize().getHeight());
	return rect;
}

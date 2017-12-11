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
	Graphics::getInstance()->drawSprite(_textureFloatGround, Vec2(0.0f, 0.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,33,14), 1);
}

Rect FloatGround::getRect()
{
	Rect rect;
	rect.setX(this->getPosition().getX());
	rect.setY(this->getPosition().getY());
<<<<<<< HEAD
	rect.setWidth(33);
	rect.setHeight(14);
=======
	rect.setWidth(_rigid->getSize().getWidth());
	rect.setHeight(_rigid->getSize().getHeight());
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	return rect;
}

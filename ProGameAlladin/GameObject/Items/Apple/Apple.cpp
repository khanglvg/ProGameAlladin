#include "Apple.h"
US_NS_JK


Apple::Apple()
{
}

Apple::Apple(const Vec2& position, const Size& size, const GameObjectType& tag):GameObject(position,size,tag)
{
	_rigid->setDensity(0);
	setScale(Vec2(1, 1));
}


Apple::Apple(GameObject* target)
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

	_textureRigidApple.setName("RigidApple.jpg");
	_textureRigidApple.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigidApple);
}

void Apple::release()
{
	delete this;
}

void Apple::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();
}

void Apple::render()
{
	Graphics::getInstance()->drawSprite(_textureRigidApple, 
										Vec2(0.0f, 1.0f), 
										getTransformMatrix(), 
										Color(255, 255, 255, 255), 
										Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 
										1);

	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,11,12), 2);
}

Rect Apple::getRect()
{
	Rect rect;
	rect.setX(this->getPosition().getX());
	rect.setY(this->getPosition().getY());
	rect.setWidth(_rigid->getSize().getWidth());
	rect.setHeight(_rigid->getSize().getHeight());
	return rect;
}





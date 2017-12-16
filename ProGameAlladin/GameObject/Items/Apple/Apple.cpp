#include "Apple.h"
#include "../../Framework/Scene.h"
US_NS_JK


Apple::Apple()
{
}

Apple::Apple(const Vec2& position, const Size& size, const GameObjectType& tag) :GameObject(position, size, tag)
{
	_rigid->setDensity(0.1);
	setScale(Vec2(1, 1));
	_rigid->setTag("apple");
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
	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (aladdin == _rigid->getCollidingBodies().end())
	{
	}
	else
		this->getCurrentScene()->removeNode(this);
}

void Apple::render()
{
	Graphics::getInstance()->drawSprite(_textureRigidApple,
		Vec2(0.0f, 1.0f),
		getTransformMatrix(),
		Color(255, 255, 255, 255),
		Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()),
		2);

	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, 11, 12), 2);
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





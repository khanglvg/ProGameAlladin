#include "Ground.h"
#include "../Aladdin.h"
US_NS_JK

Ground::Ground()
{
	_rigidGround = new RigidBody(Vec2(0, 0), Vec2(0,0), STATIC, 1 , 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(360, -405/2), Size(9330, 405));
	_rigidGround->setPosition(Vec2(300, SCREEN_HEIGHT + 405/2 - 50));
	setPosition(Vec2(100, SCREEN_HEIGHT + 405 / 2 - 50));
	_rigidGround->setTag("ground");
}

Ground::Ground(const float& sizeX, const float& sizeY, const Vec2& rigidPosition)
{
	_rigidGround = new RigidBody(rigidPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(sizeX/2, -sizeY / 2), Size(sizeX, sizeY));
	setPosition(_rigidGround->getPosition() - _rigidGround->getOffset());
	_rigidGround->setTag("ground");
}

Ground::~Ground()
{
}

void Ground::release()
{
	delete this;
}

void Ground::init()
{
	_textureGround.setName("Ground.png");
	_textureGround.setSrcFile("Resources/ground.png");
	Graphics::getInstance()->loadTexture(_textureGround);
}

void Ground::update()
{
	_position = _rigidGround->getPosition() - _rigidGround->getOffset();


}

void Ground::render()
{
	Graphics::getInstance()->drawSprite(_textureGround, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0,0, _rigidGround->getSize().getWidth(), _rigidGround->getSize().getHeight()) , 1);
}

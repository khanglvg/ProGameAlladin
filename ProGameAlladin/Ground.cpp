#include "Ground.h"
#include "Aladdin.h"
US_NS_JK

Ground::Ground()
{
	_rigidGround = new RigidBody(Vec2( 0, 0), Vec2(0,0), STATIC, 1 , 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(0,405/2), Size(2000, 405));
	_rigidGround->setPosition(Vec2(500, 500));
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
	Graphics::getInstance()->drawSprite(_textureGround, Vec2(0.0f, 0.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,800,473) , 1);
}

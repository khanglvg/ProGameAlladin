#include "Ground.h"
#include "Aladdin.h"
US_NS_JK

Ground::Ground()
{
	setPosition(Vec2( _startX - 50, _startY ));
	_rigidGround = new RigidBody(Vec2( _startX, _startY), Vec2(0,0), STATIC, 1 , 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(0,0), Size(800, 200));

	_rigidGround->setPosition(Vec2(0, SCREEN_HEIGHT + 50));
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

void Ground::render()
{
	Graphics::getInstance()->drawSprite(_textureGround, Vec2(0.0f, 0.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,800,473) , 1);
}

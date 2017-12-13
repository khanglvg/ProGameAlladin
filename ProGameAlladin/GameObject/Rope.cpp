#include "Rope.h"
#include "../../Aladdin.h"
US_NS_JK
Rope::Rope()
{
	_rigidRope = new RigidBody(Vec2(0, 0), Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(0, -100/2), Size(12, 350));
	_rigidRope->setPosition(Vec2(300, SCREEN_HEIGHT/2));
	setPosition(_rigidRope->getPosition());
	_rigidRope->setTag("rope");
}

Rope::~Rope()
{
}

void Rope::release()
{
	delete this;
}

void Rope::init()
{
	_textureRope.setName("Rope.png");
	_textureRope.setSrcFile("Resources/Rope.png");
	Graphics::getInstance()->loadTexture(_textureRope);

	_textureRigid.setName("Khang");
	_textureRigid.setSrcFile("Resources/ground.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void Rope::update()
{
	_position = _rigidRope->getPosition() - _rigidRope->getOffset();
}

void Rope::render()
{
	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.5f, 0.5f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(_rigidRope->getPosition().getX(), _rigidRope->getPosition().getY(), _rigidRope->getSize().getWidth(), _rigidRope->getSize().getHeight() - 100 / 2), 1);
}

#include "AppleToThrow.h"
#include "../Framework/Graphics.h"
US_NS_JK

AppleToThrow::AppleToThrow()
{
	float size_x = 5;
	float size_y = 5;

	auto position = Vec2(100,500);
	auto velocity = Vec2(20, 0);
	auto bodyType = DYNAMIC;
	auto density = 1;
	auto restitution = 0.5;
	auto gravityScale = 1;
	auto forces = Vec2(0, 0);
	auto impulse = 0;
	auto offset = Vec2(size_x / 5, -size_y / 2);
	auto size = Size(size_x, size_y);

	_rigidApple = new RigidBody(position, velocity, bodyType, density, restitution, gravityScale, forces, impulse, offset, size);
	setPosition(_rigidApple->getPosition());
	setScale(Vec2(2,2));
}

AppleToThrow::~AppleToThrow()
{
}

void AppleToThrow::init()
{
	_textureApple.setName("AppleToThrow.png");
	_textureApple.setSrcFile("Resources/apple1.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void AppleToThrow::update()
{
	this->_position = _rigidApple->getPosition() - _rigidApple->getOffset();
}

void AppleToThrow::release()
{
	delete _rigidApple;
	delete this;
}

void AppleToThrow::render()
{
	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(0, 0, 5, 6), 1);
}

Texture AppleToThrow::getTexture() const
{
	return _textureApple;
}

void AppleToThrow::setVelocity(const Vec2& velocity)
{
	_rigidApple->setVelocity(velocity);
}

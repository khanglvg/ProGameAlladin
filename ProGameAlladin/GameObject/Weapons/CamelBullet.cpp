#include "CamelBullet.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../pugixml/pugixml.hpp"
US_NS_JK


CamelBullet::CamelBullet(GameObject* owner, const Vec2 & position, const Size & size) :GameObject(position, size, APPLES)
{
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(0.1);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(0.7);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1, 1));
	_rigid->setTag("camelbullet");
	setCurrentScene(owner->getCurrentScene());

	_startPosion = _rigid->getPosition();

	_owner = owner;
	_isCollision = false;
}

CamelBullet::~CamelBullet()
{
}

void CamelBullet::init()
{
	_textureKnife.setName("Kcamelbullet.png");
	_textureKnife.setSrcFile("Resources/Items/CamelBullet.png");
	Graphics::getInstance()->loadTexture(_textureKnife);
}

void CamelBullet::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

	const auto enemy = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "enemy");

	if (enemy != _rigid->getCollidingBodies().end() || abs(_startPosion.getX() - _position.getX()) > 150)
	{
		setVelocity(Vec2(0,0));
		_rigid->setActive(false);
		getCurrentScene()->removeNode(this);
	}
	
}

void CamelBullet::release()
{
	delete _rigid;
	delete this;
}

void CamelBullet::render()
{

	Graphics::getInstance()->drawSprite(_textureKnife, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0,0,18,15), 2);
}

Texture CamelBullet::getTexture() const
{
	return _textureKnife;
}

void CamelBullet::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool CamelBullet::isCollision() const
{
	return _isCollision;
}

void CamelBullet::setGravityScale(const float & gravity)
{
	_rigid->setGravityScale(gravity);
}
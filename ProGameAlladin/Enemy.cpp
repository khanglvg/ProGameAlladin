#include "Enemy.h"
#include "Framework/Graphics.h"
US_NS_JK

Enemy::Enemy()
{
	_startPosition = Vec2(SCREEN_WIDTH / 3, SCREEN_HEIGHT - 50);
	_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	setPosition(_rigid->getPosition() - _rigid->getOffset());
	setScale(Vec2(-1, 1));
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	_textureEnemy.setName("Enemy.jpg");
	_textureEnemy.setSrcFile("Resources/ala.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);
}

void Enemy::release()
{
	delete this;
}

void Enemy::update()
{
}

void Enemy::render()
{
	Graphics::getInstance()->drawSprite(_textureEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(3,9,37,49), 1);
}

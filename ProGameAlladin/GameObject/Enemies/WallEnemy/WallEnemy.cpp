#include "WallEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

WallEnemy::WallEnemy()
{


}

WallEnemy::WallEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player):Enemy(position,size,tag,player)
{
	setScale(Vec2(1, 1));
	_currentState = new WallEnemyIdleState(this);
}


WallEnemy::~WallEnemy()
{
}

void WallEnemy::init()
{
	_textureWallRigid.setName("WallEnemy.jpg");
	_textureWallRigid.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureWallRigid);
}

void WallEnemy::release()
{
	delete this;
}

void WallEnemy::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();

}

void WallEnemy::render()
{
	Graphics::getInstance()->drawSprite(_textureWallRigid, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(0,0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 1);

}

Rect WallEnemy::getRect()
{
	const auto width = _animations[_actionName][_animationIndex].getWidth();
	const auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}

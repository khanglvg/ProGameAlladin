#include "WallEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

WallEnemy::WallEnemy()
{


}

WallEnemy::WallEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player) :Enemy(position, size, tag, player)
{
	_viewRange = 30;
	setScale(Vec2(1, 1));
	_currentState = new WallEnemyIdleState(this);
}


WallEnemy::~WallEnemy()
{
}

void WallEnemy::init()
{
	_textureEnemy.setName("WallEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureWallEnemy.setName("WallEnemyRigid.png");
	_textureWallEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureWallEnemy);
}

void WallEnemy::release()
{
	delete this;
}

void WallEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	_position = _rigid->getPosition() - _rigid->getOffset();
	_currentState->onUpdate();

	Enemy::update();

	EnemyState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_animationIndex = 0;
	}

}

void WallEnemy::render()
{
	auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	const auto expect = 0.05;
	if (_actionName == "WallEnemy-Idle")
	{
		rect = Rect(0, 0, 0, 0);
	}
	

	auto origin = Vec2(0.3f, 1.0f);


	//Graphics::getInstance()->drawSprite(_textureWallEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
	Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size())
			_animationIndex = 0;
	}
	
	
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

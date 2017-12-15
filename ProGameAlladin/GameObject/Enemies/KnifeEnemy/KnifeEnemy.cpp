#include "KnifeEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

KnifeEnemy::KnifeEnemy()
{
}

KnifeEnemy::KnifeEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_viewRange = 220;
	_attackRange = 140;
	_currentState = new KnifeEnemyIdleState(this);
}

KnifeEnemy::~KnifeEnemy()
{
}

void KnifeEnemy::init()
{
	_textureEnemy.setName("KnifeEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Civilian Enemies.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureKnifeEnemy.setName("KnifeEnemyRigid.png");
	_textureKnifeEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureKnifeEnemy);
}

void KnifeEnemy::release()
{
	delete this;
}

void KnifeEnemy::update()
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
	}
}

void KnifeEnemy::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.04;

	auto origin = Vec2(0.4f, 1.0f);

	//if (_actionName == "KnifeEnemy-Idle" && _animationIndex == 5)
	//{
	//	origin = Vec2(0.9f, 1.0f);
	//}
	if (_actionName == "KnifeEnemy-Idle" && _animationIndex >6 && _animationIndex <11)
	{
		origin = Vec2(0.2f, 1.0f);
	}


	Graphics::getInstance()->drawSprite(_textureKnifeEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
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

Rect KnifeEnemy::getRect()
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

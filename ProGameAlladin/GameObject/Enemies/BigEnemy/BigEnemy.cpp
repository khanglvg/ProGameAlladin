#include "BigEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

BigEnemy::BigEnemy()
{
}

BigEnemy::BigEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_attackRange = 80;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 90;
	setScale(Vec2(1, 1));
	_currentState = new BigEnemyIdleState(this);
}

BigEnemy::~BigEnemy()
{
}

void BigEnemy::init()
{
	_textureEnemy.setName("BigEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureBigEnemy.setName("BigEnemyRigid.png");
	_textureBigEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureBigEnemy);
}

void BigEnemy::release()
{
	delete this;
}

void BigEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	_position = _rigid->getPosition() - _rigid->getOffset();
	_currentState->onUpdate();

	Enemy::update();

	const auto newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
	}
}

void BigEnemy::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.05;

	auto origin = Vec2(0.3f, 1.0f);

	if (_actionName == "BigEnemy-AttackHigh" && _animationIndex >2 && _animationIndex <5)
	{
		origin = Vec2(0.8f, 1.0f);
	}

	Graphics::getInstance()->drawSprite(_textureBigEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
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

Rect BigEnemy::getRect()
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

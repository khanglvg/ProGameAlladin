#include "FatEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

FatEnemy::FatEnemy()
{
}

FatEnemy::FatEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_attackRange = 150;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 90;
	setScale(Vec2(1, 1));
	_currentState = new FatEnemyIdleState(this);
}

FatEnemy::~FatEnemy()
{
}

void FatEnemy::init()
{
	_textureEnemy.setName("FatEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);

	_textureBigEnemy.setName("FatEnemyRigid.png");
	_textureBigEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureBigEnemy);
}

void FatEnemy::release()
{
	delete this;
}

void FatEnemy::update()
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

void FatEnemy::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.1;

	auto origin = Vec2(0.3f, 1.0f);

	if (_actionName == "FatEnemy-Attack" && _animationIndex >1 && _animationIndex <4)
	{
		origin = Vec2(0.47f, 1.0f);
	}

	Graphics::getInstance()->drawSprite(_textureBigEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 1);
	Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureEnemy, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
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

Rect FatEnemy::getRect()
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

#include "ThinEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

ThinEnemy::ThinEnemy()
{
<<<<<<< HEAD
	//_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	////setPosition(_rigid->getPosition() - _rigid->getOffset());
	//setPosition(_startPosition);
	//setScale(Vec2(1, 1));

	//_currentState = new ThinEnemyIdleState(this);
}

ThinEnemy::ThinEnemy(GameObject * player, Vec2 position):Enemy(player)
{
	_target = player;
	_position = position;
	_rigid = new RigidBody(_position, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	//setPosition(_rigid->getPosition() - _rigid->getOffset());
	setPosition(_position);
	setScale(Vec2(1, 1));

	_currentState = new ThinEnemyIdleState(this);
=======
	
}

ThinEnemy::ThinEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player) 
:Enemy(position, size, tag, player)
{
	setScale(Vec2(1, 1));

	_currentState = new ThinEnemyIdleState(this);
	_rigid->setTag("ground");
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
}

ThinEnemy::~ThinEnemy()
{
}

void ThinEnemy::init()
{
	_textureEnemy.setName("ThinEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);


	_textureThinEnemy.setName("ThinEnemyRigid.png");
	_textureThinEnemy.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureThinEnemy);
}

void ThinEnemy::release()
{
	delete this;
}

void ThinEnemy::update()
{
<<<<<<< HEAD
	_position = _rigid->getPosition();
=======
//	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	_position = _rigid->getPosition() - _rigid->getOffset();
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
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

void ThinEnemy::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.1;

	Graphics::getInstance()->drawSprite(_textureThinEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 1);
	Graphics::getInstance()->drawSprite(_textureEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureEnemy, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
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

Rect ThinEnemy::getRect()
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

#include "ThinEnemy.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

ThinEnemy::ThinEnemy()
{
	float _startX = SCREEN_WIDTH / 10;
	float _startY = SCREEN_HEIGHT - 50;
	//_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), DYNAMIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	_rigid = new RigidBody(Vec2(_startX +200,_startY), Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(0, -25), Size(500, 5000));

	//setPosition(_rigid->getPosition() - _rigid->getOffset());
	setPosition(Vec2(_startX +200,_startY));
	setScale(Vec2(1, 1));

	_currentState = new ThinEnemyIdleState(this);
	_rigid->setTag("ground");
}

ThinEnemy::ThinEnemy(GameObject * player):Enemy(player)
{

//	_startPosition = Vec2(this->getPosition().getX(),this->getPosition().getY());
//	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
//	//setPosition(_rigid->getPosition() - _rigid->getOffset());
//	setPosition(_startPosition);
//	setScale(Vec2(-1, 1));
//
//#pragma region READ - XML
//	pugi::xml_document doc;
//	const auto result = doc.load_file("Resources/Enemies/Enemies.xml");
//
//	if (result)
//	{
//		for (auto animation : doc.child("Animations").children())
//		{
//			const pugi::char_t* name = animation.attribute("name").value();
//			vector<Rect> rects;
//
//			for (auto rect : animation.children())
//			{
//				rects.push_back(Rect(rect.attribute("x").as_float(),
//					rect.attribute("y").as_float(),
//					rect.attribute("w").as_float(),
//					rect.attribute("h").as_float()));
//			}
//			_animations.emplace(name, rects);
//		}
//	}
//	_currentState = new ThinEnemyIdleState(this);
}

ThinEnemy::~ThinEnemy()
{
}

void ThinEnemy::init()
{
	_textureEnemy.setName("ThinEnemy.jpg");
	_textureEnemy.setSrcFile("Resources/Enemies/Genesis 32X SCD - Aladdin - Guards.png");
	Graphics::getInstance()->loadTexture(_textureEnemy);
}

void ThinEnemy::release()
{
	delete this;
}

void ThinEnemy::update()
{
	_rigid->setSize(Size(getRect().getWidth(), getRect().getHeight()));
	//_position = _rigidAla->getPosition() - _rigidAla->getOffset();
	_currentState->onUpdate();

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
	auto width = _animations[_actionName][_animationIndex].getWidth();
	auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(this->getWidth());
	rect.setHeight(this->getHeight());
	return rect;
}

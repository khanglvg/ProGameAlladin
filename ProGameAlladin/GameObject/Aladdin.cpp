#include "Aladdin.h"
#include "../Framework/Graphics.h"
#include "../Framework/GameManager.h"
#include "../Framework/PhysicsManager.h"

US_NS_JK

Aladdin::Aladdin(const Vec2& position, const Size& size):GameObject(position, size, PLAYER)
{
	float size_x = 25;
	float size_y = 55;
	//_rigidAla = new RigidBody(Vec2(SCREEN_WIDTH / 10, SCREEN_HEIGHT - 300), Vec2(0, 0), DYNAMIC, 1, 0.5, 1,Vec2(0.0f,0.0f),0,Vec2(0,-25), Size(50,50));
	//setPosition(_rigidAla->getPosition() - _rigidAla->getOffset());
	setPosition(_rigid->getPosition());
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(10);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	//setPosition(_rigid->getPosition() - _rigid->getOffset());
	setPosition(_rigid->getPosition());
	_rigid->setTag("aladdin");
	this->setIsOwnerRight(true);

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/action2.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			const pugi::char_t* name = animation.attribute("name").value();
			vector<Rect> rects;

			for (auto rect : animation.children())
			{
				rects.push_back(Rect(rect.attribute("x").as_float(),
					rect.attribute("y").as_float(),
					rect.attribute("w").as_float(),
					rect.attribute("h").as_float()));
			}
			_animations.emplace(name, rects);
		}
	}
#pragma endregion 


	_currentState = new Idle(this);
	_currentState->onEnter();
}

Aladdin::~Aladdin()
{
}

void Aladdin::init()
{
	_textureAla.setName("Aladdin.jpg");
	_textureAla.setSrcFile("Resources/texture3.png");
	Graphics::getInstance()->loadTexture(_textureAla);

	_textureRigid.setName("AladdinRigid.png");
	_textureRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void Aladdin::release()
{
	delete this;
}

void Aladdin::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();
	_currentState->onUpdate();

	if (_rigid->getCollidingBodies().size() == 0)
	{
		_isOnTheGround = false;
		_isBesideTheStair = false;
		_isBesideTheWall = false;
		_isOnTheRope = false;
		_isOnTheFire = false;
	}
	else
	{
		auto const ground = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"ground" );;
		auto const wall = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"wall" );
		const auto stair = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"stair" );
		auto const enemy = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"enemy" );
		auto const platform = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"platform" );
		auto const rope = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "rope");
		auto const fire = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "fire");



		//
		//	collision with ground
		//
		if (ground == _rigid->getCollidingBodies().end())
			_isOnTheGround = false;
		else
			_isOnTheGround = true;

		//
		//	collision with stair
		//
		if (stair == _rigid->getCollidingBodies().end())
			_isBesideTheStair = false;
		else
		{
			
			//_stairInCollision 
			
			_isBesideTheStair = true;
		}

		//
		//	collision with wall
		//
		if (wall == _rigid->getCollidingBodies().end())
			_isBesideTheWall = false;
		else
			_isBesideTheWall = true;

		//
		//	collision with enemy
		//
		if (enemy == _rigid->getCollidingBodies().end())
			_isCollisionWithEnemy = false;
		else
			_isCollisionWithEnemy = true;
		
		//
		//	collision with platform
		//
		if (platform == _rigid->getCollidingBodies().end())
			_isOnThePlatform = false;
		else
			_isOnThePlatform = true;

		//
		// collision with rope
		//
		if (rope == _rigid->getCollidingBodies().end())
			_isOnTheRope = false;
		else
			_isOnTheRope = true;

		//
		// collision with fire
		//
		if (fire == _rigid->getCollidingBodies().end())
			_isOnTheFire = false;
		else
			_isOnTheFire = true;
	}
	


	State* newState = _currentState->checkTransition();
	
	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_currentState->onEnter();
		_animationIndex = 0;
	}


	
}

void Aladdin::render()
{
	// Vec2 là origin, được điều chỉnh trong hàm drawSprite bằng biến center để chuyển từ pixel của directx thành float (0 -> 1)
	// Left-top được xem là gốc (0.0f,0.0f)

	//if (_animationIndex >= _animations[_actionName].size())
	//	_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//_rigid->setPosition(Vec2(getPosition().getX()+ rect.getWidth() / 2, getPosition().getY() + rect.getHeight() / 2));
	//_rigid->setSize(Size(rect.getWidth(), rect.getHeight()));
	//_rigid->setOffset(Vec2(rect.getWidth()/2, rect.getHeight()/2));
	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	const auto expect = 0.05;
	auto origin = Vec2(0.5f, 1.0f);

	if (_actionName == "Grounding")
	{
		origin = Vec2(0.5f, 0.9f);
	}
	Graphics::getInstance()->drawSprite(_textureRigid, origin, getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
	Graphics::getInstance()->drawSprite(_textureAla, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureAla, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
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

#pragma region GET-SET
void Aladdin::setActionName(const string actionName)
{
	_actionName = actionName;
}

string Aladdin::getActionName() const
{
	return _actionName;
}

float Aladdin::getMaxHeight() const
{
	return _max;
}

float Aladdin::getYGround() const
{
	return _startY;
}

float Aladdin::getXGround() const
{
	return _startX;
}

int Aladdin::getIndex() const
{
	return _animationIndex;
}

Texture Aladdin::getTexture() const
{
	return _textureAla;
}

Vec2 Aladdin::getStartPosition() const
{
	return Vec2(_startX, _startY);
}

Vec2 Aladdin::getVelocity() const
{
	return _rigid->getVelocity();
}

void Aladdin::setVelocity(const Vec2& velocity) const
{
	_rigid->setVelocity(velocity);
}

Rect Aladdin::getRect()
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

bool Aladdin::isOnTheGround() const
{
	return _isOnTheGround;
}

bool Aladdin::isBesideTheWall() const
{
	return _isBesideTheWall;
}

bool Aladdin::isBesideTheStair() const
{
	return _isBesideTheStair;
}

bool Aladdin::isCollisionWithEnemy() const
{
	return _isCollisionWithEnemy;
}

bool Aladdin::isOnThePlatform() const
{
	return _isOnThePlatform;
}

bool Aladdin::isOnTheRope() const
{
	return _isOnTheRope;
}

bool Aladdin::isOnTheFire() const
{
	return _isOnTheFire;
}

void Aladdin::setIndex(const int& index)
{
	_animationIndex = index;
}
#pragma endregion

#include "Aladdin.h"
#include "../Framework/Graphics.h"
#include "../Framework/GameManager.h"
#include "../Framework/PhysicsManager.h"

US_NS_JK

Aladdin::Aladdin()
{
	float size_x = 50;
	float size_y = 55;
	//_rigidAla = new RigidBody(Vec2(SCREEN_WIDTH / 10, SCREEN_HEIGHT - 300), Vec2(0, 0), DYNAMIC, 1, 0.5, 1,Vec2(0.0f,0.0f),0,Vec2(0,-25), Size(50,50));
	_rigidAla = new RigidBody(Vec2(3200, _startY), Vec2(0, 0), DYNAMIC, 1, 0.5, 1, Vec2(0.0f, 0.0f), 0, Vec2(size_x/2, -size_y/2), Size(size_x, size_y));
	//setPosition(_rigidAla->getPosition() - _rigidAla->getOffset());
	setPosition(_rigidAla->getPosition());

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
	 _position = _rigidAla->getPosition() - _rigidAla->getOffset();
	OutputDebugString(std::to_string(_position.getY()).c_str());
	_currentState->onUpdate();

	if (_rigidAla->getCollidingBodies().size() == 0)
	{
		isOnTheGround = false;
	}
	else
	{
		auto const collider = std::find(std::begin(_rigidAla->getCollidingBodies()), std::end(_rigidAla->getCollidingBodies()),"ground" );



		if (collider == _rigidAla->getCollidingBodies().end())
		{
			isOnTheGround = false;
		}
		else
		{
			isOnTheGround = true;

		}
	}
	


	State* newState = _currentState->checkTransition();
	
	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_currentState->onEnter();
	}


	
}

void Aladdin::render()
{
	// Vec2 là origin, được điều chỉnh trong hàm drawSprite bằng biến center để chuyển từ pixel của directx thành float (0 -> 1)
	// Left-top được xem là gốc (0.0f,0.0f)

	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//_rigidAla->setSize(Size(rect.getWidth(), rect.getHeight()));
	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.1;

	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigidAla->getSize().getWidth(), _rigidAla->getSize().getHeight()), 1);
	Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
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

void Aladdin::setActionName(string actionName)
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

Texture Aladdin::getTexture()
{
	return _textureAla;
}

Vec2 Aladdin::getStartPosition() const
{
	return Vec2(_startX, _startY);
}

Vec2 Aladdin::getVelocity() const
{
	return _rigidAla->getVelocity();
}

void Aladdin::setVelocity(const Vec2& velocity)
{
	_rigidAla->setVelocity(velocity);
}

Rect Aladdin::getRect()
{ 
	auto width = _animations[_actionName][_animationIndex].getWidth();
	auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;

	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(width);
	rect.setHeight(height);
	return rect;
}

bool Aladdin::getisOnTheGround() const
{
	return isOnTheGround;
}

void Aladdin::setIndex(const int& index)
{
	_animationIndex = index;
}

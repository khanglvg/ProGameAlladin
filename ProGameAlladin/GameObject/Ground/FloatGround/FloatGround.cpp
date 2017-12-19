#include "FloatGround.h"
#include "FloatGroundNormalState.h"
#include "../../../Framework/GameManager.h"
US_NS_JK

FloatGround::FloatGround()
{
	
}

FloatGround::FloatGround(const Vec2& position, const Size& size, const GameObjectType& tag) :GameObject(position, size, tag)
{
	setScale(Vec2(1, 1));

	#pragma region READ - XML
		pugi::xml_document doc;
		const auto result = doc.load_file("Resources/Items/FloatGround.xml");
	
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
	
		_currentState = new FloatGroundNormalState(this);
}



FloatGround::~FloatGround()
{
}

void FloatGround::init()
{
	_textureFloatGround.setName("FloatGround.jpg");
	_textureFloatGround.setSrcFile("Resources/Items/fallingplatform_strip8_5_4.png");
	Graphics::getInstance()->loadTexture(_textureFloatGround);
}

void FloatGround::release()
{
	delete this;
}

void FloatGround::update()
{
	_currentState->onUpdate();

	FloatGroundState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
		_animationIndex = 0;
	}
}

void FloatGround::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.1;

	Graphics::getInstance()->drawSprite(_textureFloatGround, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureFloatGround, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
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

Rect FloatGround::getRect()
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
void FloatGround::setActionName(const string actionName)
{
	_actionName = actionName;
}

string FloatGround::getActionName() const
{
	return _actionName;
}
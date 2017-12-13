#include "Camel.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"

US_NS_JK

Camel::Camel()
{
	
}

Camel::Camel(const Vec2& position, const Size& size, const GameObjectType& tag):GameObject(position, size, tag)
{
	setScale(Vec2(1, 1));
	_rigid->setDensity(0.001);

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/Camel.xml");

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

	_currentState = new CamelIdleState(this);
}


Camel::~Camel()
{
}

void Camel::init()
{
	_textureCamel.setName("Camel.jpg");
	_textureCamel.setSrcFile("Resources/Items/Genesis 32X SCD - Aladdin - Camel.png");
	Graphics::getInstance()->loadTexture(_textureCamel);

	_textureCamelRigid.setName("CamelRigid.png");
	_textureCamelRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureCamelRigid);
}

void Camel::release()
{
	delete this;
}

void Camel::update()
{
	_currentState->onUpdate();

	CamelState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
	}
}

void Camel::render()
{
	if (_animationIndex >= _animations[_actionName].size())
		_animationIndex = 0;

	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.1;

	Graphics::getInstance()->drawSprite(_textureCamelRigid, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 1);
	Graphics::getInstance()->drawSprite(_textureCamel, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureCamel, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
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

void Camel::setActionName(string actionName)
{
	_actionName = actionName;
}

string Camel::getActionName() const
{
	return _actionName;
}

Rect Camel::getRect()
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

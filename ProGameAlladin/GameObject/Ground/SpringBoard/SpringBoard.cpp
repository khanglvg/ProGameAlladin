#include "SpringBoard.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"

US_NS_JK

SpringBoard::SpringBoard()
{
	_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	setPosition(_startPosition);
	setScale(Vec2(1, 1));

//#pragma region READ - XML
//	pugi::xml_document doc;
//	const auto result = doc.load_file("Resources/Items/Camel.xml");
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
//
//	_currentState = new SpringBoardIdleState(this);
}

SpringBoard::SpringBoard(GameObject * target) : GameObject(GameObject::GameObjectType::Springboard)
{

}

SpringBoard::~SpringBoard()
{
}

void SpringBoard::init()
{
	_textureSpringBoard.setName("SpringBoard.jpg");
	_textureSpringBoard.setSrcFile("Resources/Items/springboard.png");
	Graphics::getInstance()->loadTexture(_textureSpringBoard);
}

void SpringBoard::release()
{
	delete this;
}

void SpringBoard::update()
{
	_currentState->onUpdate();

	SpringBoardState* newState = _currentState->checkTransition();

	if (newState != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState;
	}
}

void SpringBoard::render()
{
	Graphics::getInstance()->drawSprite(_textureSpringBoard, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,43,18), 1);

	//if (_animationIndex >= _animations[_actionName].size())
	//	_animationIndex = 0;

	//const auto rect = _animations[_actionName][_animationIndex];

	////auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	//auto expect = 0.1;

	//Graphics::getInstance()->drawSprite(_textureSpringBoard, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);

	//if (_index <= expect)
	//{

	//	Graphics::getInstance()->drawSprite(_textureSpringBoard, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 1);
	//	_index += GameManager::getInstance()->getDeltaTime();
	//}
	//else
	//{
	//	_index = 0;
	//	_animationIndex++;
	//	if (_animationIndex == _animations[_actionName].size())
	//		_animationIndex = 0;

	//}
}

void SpringBoard::setActionName(string actionName)
{
	_actionName = actionName;
}

string SpringBoard::getActionName() const
{
	return _actionName;
}

Rect SpringBoard::getRect()
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

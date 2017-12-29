#include "SpringBoard.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Aladdin.h"

US_NS_JK

SpringBoard::SpringBoard()
{	
}

SpringBoard::SpringBoard(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player):GameObject(position,size,tag)
{
	setScale(Vec2(0.5, 0.5));
	_rigid->setTag("springboard");
	_player = player;


	#pragma region READ - XML
		pugi::xml_document doc;
		const auto result = doc.load_file("Resources/Items/SpringBoard.xml");
	
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
	
		_actionName = "SpringBoard-Normal";
}


SpringBoard::~SpringBoard()
{
}

void SpringBoard::init()
{
	_textureSpringBoard.setName("SpringBoard.jpg");
	_textureSpringBoard.setSrcFile("Resources/Items/spring_strip10_1_33.png");
	Graphics::getInstance()->loadTexture(_textureSpringBoard);

	_textureRigid.setName("GameObjectRigid.png");
	_textureRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void SpringBoard::release()
{
	delete this;
}

void SpringBoard::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();
	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (_player->getRigidBody()->getPosition().getY() - 7 < _rigid->getPosition().getY() - _rigid->getSize().getHeight())
	{
		_rigid->setActive(true);
	}
	else
	{
		if (aladdin == _rigid->getCollidingBodies().end())
		{
			_rigid->setActive(false);
		}
	}

	if (aladdin != _rigid->getCollidingBodies().end())
	{
		if (_actionName != "SpringBoard-OnCollision")
		{
			_actionName = "SpringBoard-OnCollision";
			_animationIndex = 0;
		}
	}
	else
	{
		if ((_actionName == "SpringBoard-OnCollision" && _animationIndex == 8) || (!_rigid->isActived() && _animationIndex == 8))
		{
			_actionName = "SpringBoard-Normal";
			_animationIndex = 0;
		}
	}
}

void SpringBoard::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	//auto expect = GameManager::getInstance()->getDeltaTime() * 5;
	auto expect = 0.03;

	auto origin = Vec2(0.5f, 1.0f);

	if (_actionName == "SpringBoard-OnCollision")
	{
		switch (_animationIndex)
		{
		case 0:
		case 2:
		case 4:
			origin = Vec2(0.5f, 0.0f);
			break;
		default:
			break;
		}
	}

	// Graphics::getInstance()->drawSprite(_textureRigid, origin, getTransformMatrix(), Color(255, 255, 255, 150), Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
	Graphics::getInstance()->drawSprite(_textureSpringBoard, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureSpringBoard, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
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

void SpringBoard::setActionName(const string actionName)
{
	_actionName = actionName;
}

string SpringBoard::getActionName() const
{
	return _actionName;
}

Rect SpringBoard::getRect()
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

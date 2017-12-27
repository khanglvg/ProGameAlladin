#include "AladdinHealth.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/Camera.h"
#include "../Aladdin.h"

US_NS_JK

AladdinHealth::AladdinHealth(Aladdin* player)
{
	_player = player;
	setScale(Vec2(0.9,0.9));

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/AladdinHealth.xml");

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

	_actionName = "10";
}

AladdinHealth::~AladdinHealth()
{
}

void AladdinHealth::init()
{
	_texture.setName("AladdinHealth");
	_texture.setSrcFile("Resources/Items/AladdinHealth.png");
	Graphics::getInstance()->loadTexture(_texture);
}

void AladdinHealth::update()
{
	_position = Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() - 80);

	switch (_player->getHealth())
	{
	case 10:
		if (_actionName != "10")
		{
			_actionName = "10";
			_animationIndex = 0;
		}
		break;
	case 9:
		if (_actionName != "9")
		{
			_actionName = "9";
			_animationIndex = 0;
		}
		break;
	case 8:
		if (_actionName != "8")
		{
			_actionName = "8";
			_animationIndex = 0;
		}
		break;
	case 7:
		if (_actionName != "7")
		{
			_actionName = "7";
			_animationIndex = 0;
		}
		break;
	case 6:
		if (_actionName != "6")
		{
			_actionName = "6";
			_animationIndex = 0;
		}
		break;
	case 5:
		if (_actionName != "5")
		{
			_actionName = "5";
			_animationIndex = 0;
		}
		break;
	case 4:
		if (_actionName != "4")
		{
			_actionName = "4";
			_animationIndex = 0;
		}
		break;
	case 3:
		if (_actionName != "3")
		{
			_actionName = "3";
			_animationIndex = 0;
		}
		break;
	case 2:
		if (_actionName != "2")
		{
			_actionName = "2";
			_animationIndex = 0;
		}
		break;
	case 1:
		if (_actionName != "1")
		{
			_actionName = "1";
			_animationIndex = 0;
		}
		break;
	case 0:
		if (_actionName != "0")
		{
			_actionName = "0";
			_animationIndex = 0;
		}
		break;
	default:
		break;
	}
}

void AladdinHealth::render()
{
	const auto rect = _animations[_actionName][_animationIndex];
	const auto expect = 0.05;
	const auto origin = Vec2(0.0f, 1.0f);


	Graphics::getInstance()->drawSprite(_texture, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 4);

	if (_index <= expect)
	{
		Graphics::getInstance()->drawSprite(_texture, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, 4);
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

void AladdinHealth::release()
{
}

void AladdinHealth::setActionName(const string& actionName)
{
	_actionName = actionName;
}

string AladdinHealth::getActionName() const
{
	return _actionName;
}

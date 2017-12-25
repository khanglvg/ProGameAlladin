#include "Item2.h"
#include "../Weapons/Fire.h"
#include "../../Framework/Scene.h"
#include "../../Framework/GameManager.h"
#include "../Aladdin.h"

US_NS_JK

Item2::Item2()
{
}

Item2::Item2(const Vec2 & position, const Size & size, const GameObjectType tag, Aladdin* target) : GameObject(position, size, tag)
{
	_aladdin = target;
	_rigid->setTag("item");

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/Items2.xml");

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
}

Item2::~Item2()
{
}

void Item2::release()
{
	delete this;
}

void Item2::init()
{
	_textureItem.setName("Item.png");
	_textureItem.setSrcFile("Resources/Items/Items.png");
	Graphics::getInstance()->loadTexture(_textureItem);

	switch (_tag)
	{
	case KILLENEMY:
		_actionName = "Kill-Enemy";
		break;
	case BONUSPOINT:
		_actionName = "BonusPoint";
		break;
	case BONUSLIFE:
		_actionName = "BonusLife";
		break;
	case ABULIFE:
		_actionName = "AbuLevel";
		break;
	case EXTRAHEART:
		_actionName = "ExtraHeart";
		break;
	case CHERRY:
		_actionName = "Cherry";
		break;
	case RESTARTPOINT:
		_actionName = "RestartPoint";
		break;
	case APPLES:
		_actionName = "Apple";
		break;
	default:
		break;
	}
}

void Item2::update()
{

}

void Item2::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	auto expect = 0.1;

	Graphics::getInstance()->drawSprite(_textureItem, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);

	if (_index <= expect)
	{

		Graphics::getInstance()->drawSprite(_textureItem, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), rect, 2);
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

Aladdin* Item2::getTarget()
{
	return _aladdin;
}

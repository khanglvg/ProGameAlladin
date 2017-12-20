#include "Item.h"
US_NS_JK

Item::Item()
{

}

Item::Item(const Vec2& position, const Size& size, const GameObjectType& tag) :GameObject(position, size, tag)
{
	_rigid->setDensity(0.001);
	_startPosition = position;
	_rigid->setTag("item");

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Items/Items.xml");

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

Item::~Item()
{
}

void Item::init()
{
}

void Item::release()
{
	delete this;
}

void Item::update()
{
}

void Item::render()
{

}

void Item::setActionName(const string actionName)
{
	_actionName = actionName;
}

string Item::getActionName() const
{
	return _actionName;
}

bool Item::isAnimationDone()
{
	return _isAnimationDone;
}

int Item::getIndex()
{
	return _animationIndex;
}

Rect Item::getRect()
{
	return Rect();
}

bool Item::getIsCollisionWithAladdin() const
{
	return _isCollisionWithAladdin;
}
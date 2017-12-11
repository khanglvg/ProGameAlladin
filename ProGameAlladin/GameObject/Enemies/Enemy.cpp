#include "Enemy.h"
US_NS_JK

Enemy::Enemy()
{

}

Enemy::Enemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* target) :GameObject(position, size, tag)
{
#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Enemies/Enemies.xml");

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

Enemy::~Enemy()
{
}

void Enemy::init()
{
}

void Enemy::release()
{
	delete this;
}

void Enemy::update()
{
}

void Enemy::render()
{

}

Rect Enemy::getRect()
{
	return Rect(0,0,0,0);
}

void Enemy::setActionName(const string actionName)
{
	_actionName = actionName;
}

string Enemy::getActionName() const
{
	return _actionName;
}

//Vec2 Enemy::getVelocity() const
//{
//	return _rigid->getVelocity();
//}
//
//void Enemy::setVelocity(const Vec2& velocity)
//{
//	_rigid->setVelocity(velocity);
//}



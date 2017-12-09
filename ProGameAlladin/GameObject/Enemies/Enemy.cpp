#include "Enemy.h"
US_NS_JK

Enemy::Enemy()
{
	//_startPosition = Vec2(SCREEN_WIDTH /3, SCREEN_HEIGHT - 50);
	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
	////setPosition(_rigid->getPosition() - _rigid->getOffset());
	//setPosition(_startPosition);
	//setScale(Vec2(-1, 1));
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

Enemy::Enemy(GameObject * target) : GameObject(GameObject::GameObjectType::Enemies)
{
	
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

void Enemy::setActionName(string actionName)
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



#include "Rope.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../Aladdin.h"

US_NS_JK

Rope::Rope()
{	
}

Rope::Rope(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player):GameObject(position,size,tag)
{
	setScale(Vec2(1, 1));
	_player = player;
}


Rope::~Rope()
{
}

void Rope::init()
{
}

void Rope::release()
{
	delete this;
}

void Rope::update()
{
	auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

	if (aladdin != _rigid->getCollidingBodies().end())
	{
		float diffX = abs((_player->getRigidPosition().getX() + _player->getRigidBody()->getSize().getWidth()/2) - _rigid->getPosition().getX());
		if (diffX < 5)
		{
			_player->setIsClimb(true);
		}
	}
}

void Rope::render() 
{

}

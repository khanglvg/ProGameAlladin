#include "Platform.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../Aladdin.h"

US_NS_JK

Platform::Platform()
{	
}

Platform::Platform(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player):GameObject(position,size,tag)
{
	_player = player;
}


Platform::~Platform()
{
}

void Platform::init()
{
}

void Platform::release()
{
	delete this;
}

void Platform::update()
{
	if (_player->getRigidBody()->getPosition().getY() + _player->getRigidBody()->getSize().getHeight()/3 < _rigid->getPosition().getY() + _rigid->getSize().getHeight()/2)
	{
		_rigid->setActive(true);
	}
	else
	{
		auto const aladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");
		if (aladdin == _rigid->getCollidingBodies().end())
		{
			_rigid->setActive(false);
		}
	}
}

void Platform::render()
{
}
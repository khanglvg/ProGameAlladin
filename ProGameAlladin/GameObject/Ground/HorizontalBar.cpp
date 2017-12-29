#include "HorizontalBar.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../Aladdin.h"

US_NS_JK

HorizontalBar::HorizontalBar()
{	
}

HorizontalBar::HorizontalBar(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player):GameObject(position,size,tag)
{
	_rigid->setBodyType(RINEMATIC);
	_rigid->setDensity(0.000001);
	setScale(Vec2(1, 1));
	_player = player;
}


HorizontalBar::~HorizontalBar()
{
}

void HorizontalBar::init()
{
}

void HorizontalBar::release()
{
	delete this;
}

void HorizontalBar::update()
{
	if (_player->getActionName() == "Fall" && _player->getRigidBody()->isActived())
	{
		float diffY = (_player->getRigidPosition().getY() - _player->getRigidBody()->getSize().getHeight() / 2) - (_rigid->getPosition().getY() + _rigid->getSize().getHeight() / 2);
		if (diffY > 15 && diffY < 20 && (_player->getPosition().getX() >= _position.getX() && _player->getPosition().getX() <= (_position.getX() + _rigid->getSize().getWidth())))
		{
			_player->setIsWing(true);
		}
	}	
}

void HorizontalBar::render()
{

}

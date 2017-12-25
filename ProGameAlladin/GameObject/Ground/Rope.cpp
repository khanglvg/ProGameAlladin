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

}

void Rope::render() 
{

}

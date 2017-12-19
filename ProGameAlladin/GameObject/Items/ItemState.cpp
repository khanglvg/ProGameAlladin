#include "ItemState.h"
#include "Item.h"

US_NS_JK

ItemState::ItemState()
{
}

ItemState::ItemState(Item * item, StateName name)
{
	_name = name;
	_item = item;

	_totalDuration = 0;

}


ItemState::~ItemState()
{

}

void ItemState::onUpdate()
{
}

void ItemState::onExit()
{
}

ItemState::StateName ItemState::GetName()
{
	return _name;
}

bool ItemState::isChange()
{
	return _isChange;
}

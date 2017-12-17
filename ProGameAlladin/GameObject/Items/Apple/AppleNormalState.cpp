#include "Apple.h"
#include "AppleNormalState.h"

US_NS_JK

AppleNormalState::AppleNormalState()
{
}

AppleNormalState::AppleNormalState(Item * item) : ItemState(item, ItemState::StateName::NORMAL)
{
	_item = item;
	_item->setActionName("Apple-Normal");
}

AppleNormalState::~AppleNormalState()
{
}

void AppleNormalState::onUpdate()
{
	auto apple = static_cast<Apple*>(_item);
}

void AppleNormalState::onExit()
{
}

ItemState * AppleNormalState::checkTransition()
{
	return nullptr;
}
 
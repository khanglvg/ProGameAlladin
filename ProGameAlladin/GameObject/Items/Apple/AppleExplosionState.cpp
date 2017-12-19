#include "Apple.h"
#include "AppleExplosionState.h"

US_NS_JK

AppleExplosionState::AppleExplosionState()
{
}

AppleExplosionState::AppleExplosionState(Item * item) : ItemState(item, ItemState::StateName::EXPLOSION)
{
	_item = item;
	_item->setActionName("Apple-Explosion");
}

AppleExplosionState::~AppleExplosionState()
{
}

void AppleExplosionState::onUpdate()
{
	auto apple = static_cast<Apple*>(_item);
}

void AppleExplosionState::onExit()
{
}

ItemState * AppleExplosionState::checkTransition()
{
	return nullptr;
}

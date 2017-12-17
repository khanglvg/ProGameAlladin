#ifndef __ITEMSTATE_H__ 
#define __ITEMSTATE_H__

#include "../GameObject.h"

NS_JK_BEGIN

class Item;

class ItemState
{
public:
	enum StateName
	{
		NORMAL, EXPLOSION, ONCOLLISION
	};
	ItemState();
	ItemState(Item* item, StateName name = StateName::NORMAL);
	~ItemState();

	virtual void onUpdate();
	virtual void onExit();
	virtual ItemState* checkTransition() = 0;

	StateName GetName();

	virtual bool isChange();

protected:
	StateName _name;
	Item* _item;

	float _totalDuration;

	bool _isChange = false;
};

NS_JK_END
#endif
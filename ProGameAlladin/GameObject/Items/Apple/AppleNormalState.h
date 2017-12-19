#ifndef __APPLENORMALSTATE_H__

#define __APPLENORMALSTATE_H__


#include "../ItemState.h"

NS_JK_BEGIN

class AppleNormalState : public ItemState
{
public:
	AppleNormalState();
	AppleNormalState(Item* enemy);
	~AppleNormalState();

	void onUpdate() override;
	void onExit() override;
	ItemState* checkTransition() override;
};


NS_JK_END

#endif

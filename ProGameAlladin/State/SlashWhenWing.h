#ifndef __SLASHWHENWING_H__
#define __SLASHWHENWING_H__
#include "StateInclude.h"

NS_JK_BEGIN
class SlashWhenWing:public State
{
	SlashWhenWing(Node*node);
	~SlashWhenWing() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif


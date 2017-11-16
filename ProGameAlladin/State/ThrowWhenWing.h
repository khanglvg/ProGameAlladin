#ifndef __THROWWHENWING_H__
#define __THROWWHENWING_H__

#include "StateInclude.h"
NS_JK_BEGIN
class ThrowWhenWing:public State
{
	ThrowWhenWing(Node*node);
	~ThrowWhenWing() override;
	void onEnter() override;
	State*checkTransition() override;
};


NS_JK_END
#endif


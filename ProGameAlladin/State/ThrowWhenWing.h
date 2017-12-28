#ifndef __THROWWHENWING_H__
#define __THROWWHENWING_H__
#include "State.h"

NS_JK_BEGIN
class ThrowWhenWing:public State
{
public:
	ThrowWhenWing(Node*node);
	~ThrowWhenWing() override;
	void onEnter() override;
	void onExit() override;
	State*checkTransition() override;
};


NS_JK_END
#endif


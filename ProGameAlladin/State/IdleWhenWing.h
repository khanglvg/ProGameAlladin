#ifndef __IDLEWHENWING_H__
#define __IDLEWHENWING_H__
#include "State.h"

NS_JK_BEGIN

class IdleWhenWing:public State
{
public:
	IdleWhenWing(Node*node);
	~IdleWhenWing() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif

#ifndef __JUMPWHILECLIMB_H__
#define __JUMPWHILECLIMB_H__

#include "StateInclude.h"
NS_JK_BEGIN
class JumpWhileClimb:public State
{
	JumpWhileClimb(Node*node);
	~JumpWhileClimb() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif


#ifndef __JUMPWHILECLIMB_H__
#define __JUMPWHILECLIMB_H__
#include "State.h"

NS_JK_BEGIN
class JumpWhileClimb:public State
{
public:
	JumpWhileClimb(Node*node);
	~JumpWhileClimb() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif __JUMPWHILECLIMB_H__


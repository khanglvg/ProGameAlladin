#ifndef __SLASHWHENCLIMB_H__

#define __SLASHWHENCLIMB_H__
#include "State.h"


NS_JK_BEGIN

class SlashWhenClimb : public State
{
public:
	SlashWhenClimb(Node* node);
	~SlashWhenClimb() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __SLASHWHENCLIMB_H__
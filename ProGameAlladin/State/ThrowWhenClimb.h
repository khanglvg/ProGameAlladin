#ifndef __THROWWHENCLIMB_H__

#define __THROWWHENCLIMB_H__
#include "State.h"


NS_JK_BEGIN

class ThrowWhenClimb : public State
{
public:
	ThrowWhenClimb(Node* node);
	~ThrowWhenClimb() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __THROWWHENCLIMB_H__
#ifndef __RUNANDJUMP_H__

#define __RUNANDJUMP_H__
#include "State.h"


NS_JK_BEGIN

class RunAndJump : public State
{
public:
	RunAndJump(Node* node);
	~RunAndJump() override;

	void onEnter() override;
	void onUpdate() override;
	State* checkTransition() override;

	enum{NONE,JUMP,FALL};
	int _state = NONE;

};

NS_JK_END

#endif __RUNANDJUMP_H__
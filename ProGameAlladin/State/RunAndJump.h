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
	State* checkTransition() override;

};

NS_JK_END

#endif __RUNANDJUMP_H__
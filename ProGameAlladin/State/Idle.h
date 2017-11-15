#ifndef __IDLE_H__

#define __IDLE_H__

#include "StateInclude.h"


NS_JK_BEGIN

class Idle: public State
{
public:
	Idle();
	~Idle() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __IDLE_H__

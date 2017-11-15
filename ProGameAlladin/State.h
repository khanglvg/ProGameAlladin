#ifndef __STATE_H__

#define __STATE_H__

#include "Framework/Input.h"

NS_JK_BEGIN

class State 
{
public:
	State();
	virtual ~State();
	virtual void onEnter();
	virtual void onUpdate();
	virtual void onExit();
	virtual State* checkTransition() = 0;
};

NS_JK_END

#endif __STATE_H__
#ifndef __STATE_H__

#define __STATE_H__

#include "StateInclude.h"

NS_JK_BEGIN

class State 
{
public:
	State(Node* node);
	virtual ~State();
	virtual void onEnter();
	virtual void onUpdate();
	virtual void onExit();
	virtual State* checkTransition() = 0;

protected:
	Node* _node;
};

NS_JK_END

#endif __STATE_H__
#ifndef __RUNANDTHROW_H__

#define __RUNANDTHROW_H__

#include "StateInclude.h"


NS_JK_BEGIN

class RunAndThrow : public State
{
public:
	RunAndThrow(Node* node);
	~RunAndThrow() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END

#endif __RUNANDTHROW_H__

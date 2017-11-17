#ifndef __RUN_H__

#define __RUN_H__
#include "State.h"


NS_JK_BEGIN

class Run: public State
{
public:
	Run(Node* node);
	~Run() override;

	void onEnter() override;

	void onUpdate() override;
	State* checkTransition() override;
	
};

NS_JK_END

#endif __RUN_H__
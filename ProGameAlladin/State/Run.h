#ifndef __RUN_H__

#define __RUN_H__

#include "StateInclude.h"

NS_JK_BEGIN

class Run: public State
{
public:
	Run();
	~Run() override;

	void onEnter() override;
	State* checkTransition() override;
	
};

NS_JK_END

#endif __RUN_H__
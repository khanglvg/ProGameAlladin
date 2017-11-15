#ifndef __SitAndThrow_H__
#define __SitAndThrow_H__

#include "StateInclude.h"
NS_JK_BEGIN
class SitAndThrow : public State
{
	Run();
	~Run() override;
	void onEnter override();
	State* checkTransition() override;


};





NS_JK_END

#endif // !__SitAndThrow_H__


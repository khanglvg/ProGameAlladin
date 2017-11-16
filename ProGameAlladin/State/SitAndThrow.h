#pragma once
#ifndef __SITANDTHROW_H__
#define __SITANDTHROW_H__

#include "StateInclude.h"
NS_JK_BEGIN
class SitAndThrow :public State
{
	SitAndThrow();
	~SitAndThrow() override;

	void onEnter() override;
	State *checkTransition() override;


};





NS_JK_END
#endif // !__SITANDTHROW_H__

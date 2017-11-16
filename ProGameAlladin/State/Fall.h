#pragma once
#ifndef __FALL_H__
#define __FALL_H__
#include "StateInclude.h"

NS_JK_BEGIN
class Fall:public JaKa::State
{
	Fall();
	~Fall() override;
	void onEnter() override;
	State*checkTransition() override;
};

NS_JK_END
#endif //!__FALL_H__

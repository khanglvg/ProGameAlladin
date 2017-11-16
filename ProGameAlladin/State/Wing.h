#pragma once
#ifndef __WING_H__
#define __WING_H__

#include "StateInclude.h"
NS_JK_BEGIN
class Wing:public JaKa::State
{
	Wing();
	~Wing() override;
	void onEnter() override;
	State*checkTransition() override;
};
NS_JK_END
#endif// !__WING_H__
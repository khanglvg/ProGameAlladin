#pragma once
#ifndef __BRAKE_H__
#define __BRAKE_H__

#include "StateInclude.h"
NS_JK_BEGIN

class Brake:public JaKa::State
{
	Brake(Node* node);
	~Brake() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif// !__BRAKE_H__

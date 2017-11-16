﻿#ifndef __JUMPANDTHROW_H__

#define __JUMPANDTHROW_H__

#include "StateInclude.h"


NS_JK_BEGIN

class JumpAndThrow : public State
{
public:
	JumpAndThrow(Node* node);
	~JumpAndThrow() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __JUMPANDTHROW_H__
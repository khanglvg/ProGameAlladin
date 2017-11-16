#pragma once
#ifndef __BeingAttackedAndDie_H__
#define __BeingAttackedAndDie_H__

#include "StateInclude.h"
NS_JK_BEGIN

class BeingAttackedAndDie:public State
{
	BeingAttackedAndDie();
	~BeingAttackedAndDie() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif// !__BeingAttackedAndDie_H__


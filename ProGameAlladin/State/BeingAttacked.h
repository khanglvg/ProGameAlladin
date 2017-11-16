#ifndef __BeingAttacked_H__
#define __BeingAttacked_H__

#include "StateInclude.h"
NS_JK_BEGIN

class BeingAttacked: public State
{
	BeingAttacked(Node* node);
	~BeingAttacked() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif !__BeingAttacked_H__

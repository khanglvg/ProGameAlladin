#ifndef __BEINGATTACKED_H__

#define __BEINGATTACKED_H__

#include "State.h"

NS_JK_BEGIN
class BeingAttacked : public State
{
public:
	BeingAttacked(Node* node);
	~BeingAttacked() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif __BEINGATTACKED_H__

#ifndef __BeingRescued_H__
#define __BeingRescued_H__
#include "State.h"


NS_JK_BEGIN

class BeingRescued:public State
{
	BeingRescued(Node* node);
	~BeingRescued() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif //!__BeingRescued_H__
 
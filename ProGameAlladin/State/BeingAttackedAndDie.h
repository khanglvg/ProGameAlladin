#ifndef __BeingAttackedAndDie_H__
#define __BeingAttackedAndDie_H__

#include "State.h"


NS_JK_BEGIN

class BeingAttackedAndDie:public State
{
public:
	BeingAttackedAndDie(Node* node);
	~BeingAttackedAndDie() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif// !__BeingAttackedAndDie_H__


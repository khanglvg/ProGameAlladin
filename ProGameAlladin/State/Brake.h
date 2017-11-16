#ifndef __BRAKE_H__
#define __BRAKE_H__
#include "State.h"


NS_JK_BEGIN

class Brake:public State
{
	Brake(Node* node);
	~Brake() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif// !__BRAKE_H__

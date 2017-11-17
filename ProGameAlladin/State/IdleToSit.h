#ifndef __IDLETOSIT_H__

#define __IDLETOSIT_H__
#include "State.h"


NS_JK_BEGIN

class IdleToSit : public State
{
public:
	IdleToSit(Node* node);
	~IdleToSit() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __IDLETOSIT_H__
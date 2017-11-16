#ifndef __IDLEWHENCLIMB_H__

#define __IDLEWHENCLIMB_H__

#include "StateInclude.h"


NS_JK_BEGIN

class IdleWhenClimb : public State
{
public:
	IdleWhenClimb(Node* node);
	~IdleWhenClimb() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __IDLEWHENCLIMB_H__

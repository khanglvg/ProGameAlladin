#ifndef __CLIMB_H__

#define __CLIMB_H__
#include "State.h"


NS_JK_BEGIN

class Climb : public State
{
public:
	Climb(Node* _node);
	~Climb() override;

	void onEnter() override;
	void onUpdate() override;
	State* checkTransition() override;

};

NS_JK_END

#endif __CLIMB_H__


#ifndef __PUSH_H__

#define __PUSH_H__

#include "StateInclude.h"


NS_JK_BEGIN

class Push : public State
{
public:
	Push(Node* node);
	~Push() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __PUSH_H__
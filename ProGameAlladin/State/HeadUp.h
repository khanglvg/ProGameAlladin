#ifndef __HEADUP_H__

#define __HEADUP_H__
#include "State.h"


NS_JK_BEGIN

class HeadUp : public State
{
public:
	HeadUp(Node* node);
	~HeadUp() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __HEADUP_H__
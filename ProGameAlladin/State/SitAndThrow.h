#ifndef __SITANDTHROW_H__

#define __SITANDTHROW_H__
#include "State.h"


NS_JK_BEGIN

class SitAndThrow : public State
{
public:
	SitAndThrow(Node *node);
	~SitAndThrow() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __SITANDTHROW_H__
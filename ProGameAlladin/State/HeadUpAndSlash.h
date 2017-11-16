#ifndef __HEADUPANDSLASH_H__

#define __HEADUPANDSLASH_H__
#include "State.h"


NS_JK_BEGIN

class HeadUpAndSlash : public State
{
public:
	HeadUpAndSlash(Node* node);
	~HeadUpAndSlash() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __HEADUPANDSLASH_H__
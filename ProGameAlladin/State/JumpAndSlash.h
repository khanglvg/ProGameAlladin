#ifndef __JUMPANDSLASH_H__

#define __JUMPANDSLASH_H__

#include "StateInclude.h"


NS_JK_BEGIN

class JumpAndSlash : public State
{
public:
	JumpAndSlash(Node* node);
	~JumpAndSlash() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __JUMPANDSLASH_H__
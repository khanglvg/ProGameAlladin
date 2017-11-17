#ifndef __JUMPANDSLASH_H__

#define __JUMPANDSLASH_H__
#include "State.h"


NS_JK_BEGIN

class JumpAndSlash : public State
{
public:
	JumpAndSlash(Node* node);
	~JumpAndSlash() override;
	void onEnter() override;
	void onUpdate() override;
	State* checkTransition() override;

private:
	enum{NONE,JUMP,FALL};
	int _state = NONE;
};

NS_JK_END
#endif __JUMPANDSLASH_H__
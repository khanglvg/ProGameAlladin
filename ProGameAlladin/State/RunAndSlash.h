#ifndef __RUNANDSLASH_H__
#define __RUNANDSLASH_H__
#include "State.h"

NS_JK_BEGIN
class RunAndSlash:public State
{
public:
	RunAndSlash(Node* node);
	~RunAndSlash() override;
	void onEnter() override;
	State* checkTransition() override;
	
};
NS_JK_END
#endif// !__RUNANDSLASH_H__

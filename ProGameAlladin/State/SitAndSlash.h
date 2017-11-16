#ifndef __SITANDSLASH_H__

#define __SITANDSLASH_H__

#include "StateInclude.h"


NS_JK_BEGIN

class SitAndSlash : public State
{
	SitAndSlash(Node*node);
	~SitAndSlash() override;
	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END
#endif __SITANDSLASH_H__
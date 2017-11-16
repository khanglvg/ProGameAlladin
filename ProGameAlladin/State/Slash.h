#ifndef __SLASH_H__

#define __SLASH_H__
#include "State.h"


NS_JK_BEGIN

class Slash : public State
{
public:
	Slash(Node* node);
	~Slash() override;

	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END

#endif __SLASH_H__
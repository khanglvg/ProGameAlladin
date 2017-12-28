#ifndef __WING_H__

#define __WING_H__
#include "State.h"


NS_JK_BEGIN

class Wing: public State
{
public:
	Wing(Node* node);
	~Wing() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State*checkTransition() override;
};

NS_JK_END
#endif// !__WING_H__
#ifndef __FALL_H__
#define __FALL_H__
#include "State.h"

NS_JK_BEGIN
class Fall:public State
{
public:
	Fall(Node* node);
	~Fall() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State*checkTransition() override;
};

NS_JK_END
#endif //!__FALL_H__

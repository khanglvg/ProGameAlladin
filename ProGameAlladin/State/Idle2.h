#ifndef __IDLE2_H__
#define __IDLE2_H__

#include "State.h"

NS_JK_BEGIN
class Idle2:public State
{
public:
	Idle2(Node*node);
	~Idle2() override;
	void onEnter() override;
	State* checkTransition() override;
	
	
};
NS_JK_END
#endif //!__IDLE2_H__

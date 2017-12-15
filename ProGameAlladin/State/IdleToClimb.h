#ifndef __IDLETOCLIMB_H__
#define __IDLETOCLIMB_H__

#include "State.h"
NS_JK_BEGIN

class IdleToClimb:public State
{
public:
	IdleToClimb(Node*node);
	~IdleToClimb() override;
	void onEnter() override;
	void onUpdate() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif //!__IDLETOCLIMB_H__

#ifndef __FLIP_H__
#define __FLIP_H__
#include "State.h"

NS_JK_BEGIN

class Flip:public State
{
public:
	Flip(Node*node);
	~Flip() override;
	void onEnter() override;
	State*checkTransition() override;

	
};
NS_JK_END
#endif // !__FLIP_H__


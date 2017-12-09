#ifndef __GROUNDING_H__
#define __GROUNDING_H__

#include "State.h"
NS_JK_BEGIN
class Grounding:public State
{
public:
	Grounding(Node*node);
	~Grounding() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif //!__GROUNDING_H__


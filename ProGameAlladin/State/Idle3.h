#ifndef __IDLE3_H__
#define __IDLE3_H__
#include "../Framework/definitions.h"
#include "State.h"
NS_JK_BEGIN

class Idle3:public State
{
public:
	Idle3(Node*node);
	~Idle3() override;
	void onEnter() override;
	State* checkTransition() override;
};
NS_JK_END
#endif //! __IDLE3_H__

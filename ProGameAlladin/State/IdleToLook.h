#ifndef __IDLETOLOOK_H__
#define __IDLETOLOOK_H__
#include "../Framework/definitions.h"
#include "State.h"

NS_JK_BEGIN
class IdleToLook : public State
{
public:
	IdleToLook(Node* node);
	~IdleToLook() override;
	void onEnter() override;
	State*checkTransition() override;
	
};
NS_JK_END
#endif //!__IDLETOLOOK_H__


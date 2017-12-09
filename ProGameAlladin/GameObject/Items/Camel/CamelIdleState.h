#ifndef __CAMELIDLESTATE_H__

#define __CAMELIDLESTATE_H__


#include "CamelState.h"
#include "Camel.h"

NS_JK_BEGIN

class CamelIdleState : public CamelState
{
public:
	CamelIdleState();
	CamelIdleState(Camel* camel);
	~CamelIdleState();

	void onExit() override;
	CamelState* checkTransition() override;
};


NS_JK_END

#endif

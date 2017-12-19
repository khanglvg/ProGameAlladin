#ifndef __SPINGBOARDIDLESTATE_H__

#define __SPINGBOARDIDLESTATE_H__


#include "SpringBoardState.h"
#include "SpringBoard.h"

NS_JK_BEGIN

class SpringBoardIdleState : public SpringBoardState
{
public:
	SpringBoardIdleState();
	SpringBoardIdleState(SpringBoard* springBoard);
	~SpringBoardIdleState();

	void onExit() override;
	SpringBoardState* checkTransition() override;
};


NS_JK_END

#endif

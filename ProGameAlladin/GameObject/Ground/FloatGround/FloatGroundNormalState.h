#ifndef __FLOATGROUNDNORMALSTATE_H__

#define __FLOATGROUNDNORMALSTATE_H__


#include "FloatGroundState.h"
#include "FloatGround.h"

NS_JK_BEGIN

class FloatGroundNormalState : public FloatGroundState
{
public:
	FloatGroundNormalState();
	FloatGroundNormalState(FloatGround* springBoard);
	~FloatGroundNormalState();

	void onExit() override;
	FloatGroundState* checkTransition() override;
};


NS_JK_END

#endif

#ifndef __FLOATGROUNDFALLINGSTATE_H__

#define __FLOATGROUNDFALLINGSTATE_H__


#include "FloatGroundState.h"
#include "FloatGround.h"

NS_JK_BEGIN

class FloatGroundFallingState : public FloatGroundState
{
public:
	FloatGroundFallingState();
	FloatGroundFallingState(FloatGround* floatground);
	~FloatGroundFallingState();

	void onUpdate() override;
	void onExit() override;
	FloatGroundState* checkTransition() override;
private:
	FloatGround* _floatGround;
};


NS_JK_END

#endif

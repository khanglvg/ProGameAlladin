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

	void onUpdate() override;
	void onExit() override;
	FloatGroundState* checkTransition() override;
private:
	FloatGround* _floatGround;
	float _index = 0;
	bool _check = false;
};


NS_JK_END

#endif

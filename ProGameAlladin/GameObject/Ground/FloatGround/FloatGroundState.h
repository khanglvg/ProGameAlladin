#ifndef __FLOATGROUNDSTATE_H__ 
#define __FLOATGROUNDSTATE_H__

#include "../../GameObject.h"

NS_JK_BEGIN

class FloatGround;

class FloatGroundState
{
public:
	enum StateName
	{
		Normal, OnCollision
	};
	FloatGroundState();
	FloatGroundState(FloatGround* camel, StateName name = StateName::Normal);
	~FloatGroundState();

	virtual void onUpdate();
	virtual void onExit();
	virtual FloatGroundState* checkTransition() = 0;

	StateName GetName();

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool IsAttackedPlayer();
	void SetIsAttackedPlayer(bool value);

protected:
	StateName _name;
	FloatGround* _springBoard;

	float _totalDuration;

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool _isAttackedPlayer;
};

NS_JK_END
#endif
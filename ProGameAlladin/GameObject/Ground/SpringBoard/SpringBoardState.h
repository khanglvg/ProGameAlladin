#ifndef __SPRINGBOARDSTATE_H__ 
#define __SPRINGBOARDSTATE_H__

#include "../../GameObject.h"

NS_JK_BEGIN

class SpringBoard;

class SpringBoardState
{
public:
	enum StateName
	{
		Idle, OnCollision
	};
	SpringBoardState();
	SpringBoardState(SpringBoard* camel, StateName name = StateName::Idle);
	~SpringBoardState();

	virtual void onUpdate();
	virtual void onExit();
	virtual SpringBoardState* checkTransition() = 0;

	StateName GetName();

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool IsAttackedPlayer();
	void SetIsAttackedPlayer(bool value);

protected:
	StateName _name;
	SpringBoard* _springBoard;

	float _totalDuration;

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool _isAttackedPlayer;
};

NS_JK_END
#endif
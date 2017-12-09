#ifndef __CAMELSTATE_H__ 
#define __CAMELSTATE_H__

#include "../../GameObject.h"

NS_JK_BEGIN

class Camel;

class CamelState
{
public:
	enum StateName
	{
		Idle, OnCollision
	};
	CamelState();
	CamelState(Camel* camel, StateName name = StateName::Idle);
	~CamelState();

	virtual void onUpdate();
	virtual void onExit();
	virtual CamelState* checkTransition() = 0;

	StateName GetName();

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool IsAttackedPlayer();
	void SetIsAttackedPlayer(bool value);

protected:
	StateName _name;
	Camel* _camel;

	float _totalDuration;

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool _isAttackedPlayer;
};

NS_JK_END
#endif
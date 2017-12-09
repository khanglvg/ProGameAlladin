#ifndef __ENEMYSTATE_H__ 
#define __ENEMYSTATE_H__

#include "../GameObject.h"

NS_JK_BEGIN

class Enemy;

class EnemyState
{
public:
	enum StateName
	{
		Idle, Walk, Attack, Damage
	};
	EnemyState();
	EnemyState(Enemy* enemy, StateName name = StateName::Idle);
	~EnemyState();

	virtual void onUpdate();
	virtual void onExit();
	virtual EnemyState* checkTransition() = 0;

	StateName GetName();

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool IsAttackedPlayer();
	void SetIsAttackedPlayer(bool value);

protected:
	StateName _name;
	Enemy* _enemy;

	float _totalDuration;

	//special for attack state (used to make sure that player is attacked once at each attackState)
	bool _isAttackedPlayer;
};

NS_JK_END
#endif
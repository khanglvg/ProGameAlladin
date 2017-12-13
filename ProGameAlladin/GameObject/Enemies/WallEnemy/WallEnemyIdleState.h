#ifndef __WALLENEMYIDLESTATE_H__

#define __WALLENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class WallEnemyIdleState : public EnemyState
{
public:
	WallEnemyIdleState();
	WallEnemyIdleState(Enemy* enemy);
	~WallEnemyIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

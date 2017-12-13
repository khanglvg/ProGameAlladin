#ifndef __THINENEMYWALKSTATE_H__

#define __THINENEMYWALKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class ThinEnemyWalkState : public EnemyState
{
public:
	ThinEnemyWalkState();
	ThinEnemyWalkState(Enemy* enemy);
	~ThinEnemyWalkState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

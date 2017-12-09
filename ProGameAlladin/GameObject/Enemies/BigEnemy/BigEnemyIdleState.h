#ifndef __BIGENEMYIDLESTATE_H__

#define __BIGENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyIdleState : public EnemyState
{
public:
	BigEnemyIdleState();
	BigEnemyIdleState(Enemy* enemy);
	~BigEnemyIdleState();

	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

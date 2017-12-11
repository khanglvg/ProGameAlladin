#ifndef __THINENEMYATTACKSTATE_H__

#define __THINENEMYATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class ThinEnemyAttackState : public EnemyState
{
public:
	ThinEnemyAttackState();
	ThinEnemyAttackState(Enemy* enemy);
	~ThinEnemyAttackState();

	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

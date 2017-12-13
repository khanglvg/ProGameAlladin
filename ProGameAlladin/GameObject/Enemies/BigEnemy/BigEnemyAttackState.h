#ifndef __BIGENEMYATTACKSTATE_H__

#define __BIGENEMYATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyAttackState : public EnemyState
{
public:
	BigEnemyAttackState();
	BigEnemyAttackState(Enemy* enemy);
	~BigEnemyAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

#ifndef __ENEMYEXPLOSIONSTATE_H__

#define __ENEMYEXPLOSIONSTATE_H__


#include "EnemyState.h"

NS_JK_BEGIN

class EnemyExplosionState : public EnemyState
{
public:
	EnemyExplosionState();
	EnemyExplosionState(Enemy* enemy);
	~EnemyExplosionState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

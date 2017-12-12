#ifndef __BIGENEMYWALKSTATE_H__

#define __BIGENEMYWALKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyWalkState : public EnemyState
{
public:
	BigEnemyWalkState();
	BigEnemyWalkState(Enemy* enemy);
	~BigEnemyWalkState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	Enemy* _enemy;
};


NS_JK_END

#endif

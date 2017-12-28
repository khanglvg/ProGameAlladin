#ifndef __FATENEMYIDLESTATE_H__

#define __FATENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class FatEnemyIdleState : public EnemyState
{
public:
	FatEnemyIdleState();
	FatEnemyIdleState(Enemy* enemy);
	~FatEnemyIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;

private:
	float _expect = 0;
};


NS_JK_END

#endif

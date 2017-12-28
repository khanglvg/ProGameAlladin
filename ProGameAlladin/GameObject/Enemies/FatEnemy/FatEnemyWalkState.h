#ifndef __FATENEMYWALKSTATE_H__

#define __FATENEMYWALKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class FatEnemyWalkState : public EnemyState
{
public:
	FatEnemyWalkState();
	FatEnemyWalkState(Enemy* enemy);
	~FatEnemyWalkState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;

private:
	bool _expect = 0;
};


NS_JK_END

#endif

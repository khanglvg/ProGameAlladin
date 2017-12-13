#ifndef __FATENEMYINATTACKEDSTATE_H__

#define __FATENEMYINATTACKEDSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class FatEnemyInAttackedState : public EnemyState
{
public:
	FatEnemyInAttackedState();
	FatEnemyInAttackedState(Enemy* enemy);
	~FatEnemyInAttackedState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

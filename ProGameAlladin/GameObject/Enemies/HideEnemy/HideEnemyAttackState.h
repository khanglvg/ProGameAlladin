#ifndef __HIDEENEMYATTACKSTATE_H__

#define __HIDEENEMYATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class HideEnemyAttackState : public EnemyState
{
public:
	HideEnemyAttackState();
	HideEnemyAttackState(Enemy* enemy);
	~HideEnemyAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

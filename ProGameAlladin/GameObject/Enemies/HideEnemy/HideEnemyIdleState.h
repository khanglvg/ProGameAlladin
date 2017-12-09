#ifndef __HIDEENEMYIDLESTATE_H__

#define __HIDEENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class HideEnemyIdleState : public EnemyState
{
public:
	HideEnemyIdleState();
	HideEnemyIdleState(Enemy* enemy);
	~HideEnemyIdleState();

	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

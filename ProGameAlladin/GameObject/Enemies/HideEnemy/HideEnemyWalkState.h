#ifndef __HIDEENEMYWALKSTATE_H__

#define __HIDEENEMYWALKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class HideEnemyWalkState : public EnemyState
{
public:
	HideEnemyWalkState();
	HideEnemyWalkState(Enemy* enemy);
	~HideEnemyWalkState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

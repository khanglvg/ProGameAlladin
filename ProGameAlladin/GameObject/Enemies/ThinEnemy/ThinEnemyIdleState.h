#ifndef __THINENEMYIDLESTATE_H__

#define __THINENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class ThinEnemyIdleState : public EnemyState
{
public:
	ThinEnemyIdleState();
	ThinEnemyIdleState(Enemy* enemy);
	~ThinEnemyIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	Enemy* _enemy;
};


NS_JK_END

#endif

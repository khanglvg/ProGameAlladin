#ifndef __KNIFEENEMYIDLESTATE_H__

#define __KNIFEENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class KnifeEnemyIdleState : public EnemyState
{
public:
	KnifeEnemyIdleState();
	KnifeEnemyIdleState(Enemy* enemy);
	~KnifeEnemyIdleState();

	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

#ifndef __BIGENEMYDEFIANTSTATE_H__

#define __BIGENEMYDEFIANTSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyDefiantState : public EnemyState
{
public:
	BigEnemyDefiantState();
	BigEnemyDefiantState(Enemy* enemy);
	~BigEnemyDefiantState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

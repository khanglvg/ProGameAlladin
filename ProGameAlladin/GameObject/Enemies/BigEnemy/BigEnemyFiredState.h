#ifndef __BIGENEMYFIREDSTATE_H__

#define __BIGENEMYFIREDSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyFiredState : public EnemyState
{
public:
	BigEnemyFiredState();
	BigEnemyFiredState(Enemy* enemy);
	~BigEnemyFiredState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
};


NS_JK_END

#endif

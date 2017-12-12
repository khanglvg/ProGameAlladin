#ifndef __BIGENEMYINATTACKEDSTATE_H__

#define __BIGENEMYINATTACKEDSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class BigEnemyInAttackedState : public EnemyState
{
public:
	BigEnemyInAttackedState();
	BigEnemyInAttackedState(Enemy* enemy);
	~BigEnemyInAttackedState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	Enemy* _enemy;
};


NS_JK_END

#endif

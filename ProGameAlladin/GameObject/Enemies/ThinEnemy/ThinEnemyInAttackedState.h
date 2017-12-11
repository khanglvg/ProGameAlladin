#ifndef __THINENEMYINATTACKEDSTATE_H__

#define __THINENEMYINATTACKEDSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class ThinEnemyInAttackedState : public EnemyState
{
public:
	ThinEnemyInAttackedState();
	ThinEnemyInAttackedState(Enemy* enemy);
	~ThinEnemyInAttackedState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	Enemy* _enemy;
};


NS_JK_END

#endif

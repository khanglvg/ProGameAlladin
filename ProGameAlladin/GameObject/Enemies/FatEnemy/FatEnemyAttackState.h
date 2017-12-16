#ifndef __FATENEMYATTACKSTATE_H__

#define __FATENEMYATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class FatEnemyAttackState : public EnemyState
{
public:
	FatEnemyAttackState();
	FatEnemyAttackState(Enemy* enemy);
	~FatEnemyAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	bool _isThrew = false;
};


NS_JK_END

#endif

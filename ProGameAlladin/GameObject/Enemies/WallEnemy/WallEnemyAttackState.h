#ifndef __WALLENEMYATTACKSTATE_H__

#define __WALLENEMYATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class WallEnemyAttackState : public EnemyState
{
public:
	WallEnemyAttackState();
	WallEnemyAttackState(Enemy* enemy);
	~WallEnemyAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	bool _isThrew;
};


NS_JK_END

#endif

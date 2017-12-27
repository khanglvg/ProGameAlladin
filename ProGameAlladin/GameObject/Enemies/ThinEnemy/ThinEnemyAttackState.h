#ifndef __THINENEMYATTACKSTATE_H__

#define __THINENEMYATTACKSTATE_H__


#include "../EnemyState.h"
#include "../../Weapons/Weapon.h"

NS_JK_BEGIN

class ThinEnemyAttackState : public EnemyState
{
public:
	ThinEnemyAttackState();
	ThinEnemyAttackState(Enemy* enemy);
	~ThinEnemyAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;

private:
	Weapon* _weapon;
};


NS_JK_END

#endif

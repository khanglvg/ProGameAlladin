#ifndef __TRANSFORMATTACKSTATE_H__

#define __TRANSFORMATTACKSTATE_H__


#include "../../EnemyState.h"

NS_JK_BEGIN

class TransformAttackState : public EnemyState
{
public:
	TransformAttackState();
	TransformAttackState(Enemy* enemy);
	~TransformAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	bool _isThrew;
};


NS_JK_END

#endif

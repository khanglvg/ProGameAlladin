#ifndef __TRANSFORMIDLESTATE_H__

#define __TRANSFORMIDLESTATE_H__


#include "../../EnemyState.h"

NS_JK_BEGIN

class TransformIdleState : public EnemyState
{
public:
	TransformIdleState();
	TransformIdleState(Enemy* enemy);
	~TransformIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	float _delay;
};


NS_JK_END

#endif

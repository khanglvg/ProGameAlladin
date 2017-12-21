#ifndef __JAFARIDLESTATE_H__

#define __JAFARIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class JafarIdleState : public EnemyState
{
public:
	JafarIdleState();
	JafarIdleState(Enemy* enemy);
	~JafarIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	float _delay;
};


NS_JK_END

#endif

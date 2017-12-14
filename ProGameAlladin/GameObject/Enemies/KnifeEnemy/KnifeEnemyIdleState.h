#ifndef __KNIFEENEMYIDLESTATE_H__

#define __KNIFEENEMYIDLESTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class KnifeEnemyIdleState : public EnemyState
{
public:
	KnifeEnemyIdleState();
	KnifeEnemyIdleState(Enemy* enemy);
	~KnifeEnemyIdleState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	bool _isThrew;
};


NS_JK_END

#endif

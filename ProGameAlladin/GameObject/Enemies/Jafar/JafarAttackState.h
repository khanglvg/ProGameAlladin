#ifndef __JAFARATTACKSTATE_H__

#define __JAFARATTACKSTATE_H__


#include "../EnemyState.h"

NS_JK_BEGIN

class JafarAttackState : public EnemyState
{
public:
	JafarAttackState();
	JafarAttackState(Enemy* enemy);
	~JafarAttackState();

	void onUpdate() override;
	void onExit() override;
	EnemyState* checkTransition() override;
private:
	int _bulletNum;
	float _delayBullet;
};


NS_JK_END

#endif

#ifndef __KNIFEENEMY_H__

#define __KNIFEENEMY_H__

#include "../Enemy.h"
#include "KnifeEnemyIdleState.h"

NS_JK_BEGIN

class KnifeEnemy : public Enemy
{
public:
	KnifeEnemy();
	KnifeEnemy(GameObject * player);
	~KnifeEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
};

NS_JK_END
#endif
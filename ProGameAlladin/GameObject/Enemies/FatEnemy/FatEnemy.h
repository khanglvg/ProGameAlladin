#ifndef __FATENEMY_H__

#define __FATENEMY_H__

#include "../Enemy.h"
#include "FatEnemyIdleState.h"

NS_JK_BEGIN

class FatEnemy : public Enemy
{
public:
	FatEnemy();
	FatEnemy(GameObject * player);
	~FatEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
};

NS_JK_END
#endif
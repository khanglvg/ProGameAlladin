#ifndef __HIDEENEMY_H__

#define __HIDEENEMY_H__

#include "../Enemy.h"
#include "HideEnemyIdleState.h"

NS_JK_BEGIN

class HideEnemy : public Enemy
{
public:
	HideEnemy();
	HideEnemy(GameObject * player);
	~HideEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
};

NS_JK_END
#endif
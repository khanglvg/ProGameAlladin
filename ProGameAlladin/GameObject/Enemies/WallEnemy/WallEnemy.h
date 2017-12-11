#ifndef __WALLENEMY_H__

#define __WALLENEMY_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class WallEnemy : public Enemy
{
public:
	WallEnemy();
	WallEnemy(GameObject * player);
	~WallEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
	Texture _textureWallRigid;
	RigidBody *_rigidWall;
};

NS_JK_END
#endif
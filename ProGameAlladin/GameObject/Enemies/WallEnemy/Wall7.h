#ifndef __WALL7_H__

#define __WALL7_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall7 : public Enemy
{
public:
	Wall7();
	Wall7(GameObject * player);
	~Wall7();

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
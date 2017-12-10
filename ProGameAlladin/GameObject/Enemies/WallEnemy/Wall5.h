#ifndef __WALL5_H__

#define __WALL5_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall5 : public Enemy
{
public:
	Wall5();
	Wall5(GameObject * player);
	~Wall5();

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
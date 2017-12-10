#ifndef __WALL1_H__

#define __WALL1_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall1 : public Enemy
{
public:
	Wall1();
	Wall1(GameObject * player);
	~Wall1();

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
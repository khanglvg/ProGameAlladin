#ifndef __WALL10_H__

#define __WALL10_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall10 : public Enemy
{
public:
	Wall10();
	Wall10(GameObject * player);
	~Wall10();

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
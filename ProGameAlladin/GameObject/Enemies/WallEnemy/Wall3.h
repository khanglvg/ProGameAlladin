#ifndef __WALL3_H__

#define __WALL3_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall3 : public Enemy
{
public:
	Wall3();
	Wall3(GameObject * player);
	~Wall3();

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
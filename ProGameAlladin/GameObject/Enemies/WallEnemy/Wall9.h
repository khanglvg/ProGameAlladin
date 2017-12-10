#ifndef __WALL9_H__

#define __WALL9_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall9 : public Enemy
{
public:
	Wall9();
	Wall9(GameObject * player);
	~Wall9();

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
#ifndef __WALL4_H__

#define __WALL4_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall4 : public Enemy
{
public:
	Wall4();
	Wall4(GameObject * player);
	~Wall4();

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
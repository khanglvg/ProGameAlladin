#ifndef __WALL6_H__

#define __WALL6_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall6 : public Enemy
{
public:
	Wall6();
	Wall6(GameObject * player);
	~Wall6();

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
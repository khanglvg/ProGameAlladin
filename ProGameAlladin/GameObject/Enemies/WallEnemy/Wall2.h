#ifndef __WALL2_H__

#define __WALL2_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall2 : public Enemy
{
public:
	Wall2();
	Wall2(GameObject * player);
	~Wall2();

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
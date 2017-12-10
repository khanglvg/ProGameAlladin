#ifndef __WALL8_H__

#define __WALL8_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class Wall8 : public Enemy
{
public:
	Wall8();
	Wall8(GameObject * player);
	~Wall8();

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
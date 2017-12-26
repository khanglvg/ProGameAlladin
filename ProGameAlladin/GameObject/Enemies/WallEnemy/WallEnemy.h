#ifndef __WALLENEMY_H__

#define __WALLENEMY_H__

#include "../Enemy.h"
#include "WallEnemyIdleState.h"

NS_JK_BEGIN

class WallEnemy : public Enemy
{
public:
	WallEnemy();
	WallEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject * player);
	~WallEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
private:
	Texture _textureWallEnemy;

	bool _isAttacked;
};

NS_JK_END
#endif
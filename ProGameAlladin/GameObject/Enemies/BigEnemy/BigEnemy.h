#ifndef __BIGENEMY_H__

#define __BIGENEMY_H__

#include "../Enemy.h"
#include "BigEnemyIdleState.h"

NS_JK_BEGIN

class BigEnemy : public Enemy
{
public:
	BigEnemy();
	BigEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
	~BigEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;

private:
	Texture _textureBigEnemy;
};

NS_JK_END
#endif
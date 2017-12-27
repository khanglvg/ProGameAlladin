#ifndef __FATENEMY_H__

#define __FATENEMY_H__

#include "../Enemy.h"
#include "FatEnemyIdleState.h"

NS_JK_BEGIN

class FatEnemy : public Enemy
{
public:
	FatEnemy();
	FatEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
	~FatEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
private:
	Texture _textureBigEnemy;

	bool _isAttacked;
};

NS_JK_END
#endif
#ifndef __HIDEENEMY_H__

#define __HIDEENEMY_H__

#include "../Enemy.h"
#include "HideEnemyIdleState.h"

NS_JK_BEGIN

class HideEnemy : public Enemy
{
public:
	HideEnemy();
	HideEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
	~HideEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
private:
	Texture _textureHideEnemy;

	bool _isAttacked;
};

NS_JK_END
#endif
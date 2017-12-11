#ifndef __THINENEMY_H__

#define __THINENEMY_H__

#include "../Enemy.h"
#include "ThinEnemyIdleState.h"

NS_JK_BEGIN

class ThinEnemy : public Enemy
{
public:
	ThinEnemy();
<<<<<<< HEAD
	ThinEnemy(GameObject * player, Vec2 position);
=======
	ThinEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	~ThinEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;

	Texture _textureThinEnemy;
};

NS_JK_END
#endif
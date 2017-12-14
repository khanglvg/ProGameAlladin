#ifndef __THINENEMY_H__

#define __THINENEMY_H__

#include "../Enemy.h"
#include "ThinEnemyIdleState.h"

NS_JK_BEGIN

class ThinEnemy : public Enemy
{
public:
	ThinEnemy();
	ThinEnemy(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
	~ThinEnemy();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;

	
private:
	Texture _textureThinEnemy;
};

NS_JK_END
#endif
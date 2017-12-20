#ifndef __APPLEENEMY_H__

#define __APPLEENEMY_H__

#include "../Item.h"
//#include "ThinEnemyIdleState.h"

NS_JK_BEGIN

class Apple : public Item
{
public:
	Apple();
	Apple(const Vec2& position, const Size& size, const GameObjectType& tag);
	~Apple();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;

	
private:
	Texture _textureApple;
};

NS_JK_END
#endif
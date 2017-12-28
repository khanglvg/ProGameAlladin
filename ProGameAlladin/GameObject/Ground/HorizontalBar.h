#ifndef __HORIZONTALBAR_H__

#define __HORIZONTALBAR_H__
#include "../../Framework/definitions.h"
#include "../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"

NS_JK_BEGIN

class Aladdin;

class HorizontalBar : public GameObject
{
public:
	HorizontalBar();//not use
	HorizontalBar(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player);

	~HorizontalBar() override;

	void init()override;
	void release()override;
	void update()override;
	void render()override;

private:
	Aladdin* _player;
};

NS_JK_END
#endif
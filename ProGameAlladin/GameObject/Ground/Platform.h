#ifndef __PLATFORM_H__

#define __PLATFORM_H__
#include "../../Framework/definitions.h"
#include "../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"

NS_JK_BEGIN

class Aladdin;

class Platform : public GameObject
{
public:
	Platform();//not use
	Platform(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player);

	~Platform() override;

	void init()override;
	void release()override;
	void update()override;
	void render()override;

protected:
	Aladdin* _player;
};

NS_JK_END
#endif
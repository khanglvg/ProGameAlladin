#ifndef __APPLE_H__

#define __APPLE_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"
#include "../../../Framework/RigidBody.h"

NS_JK_BEGIN

class Apple : public GameObject
{
public:
	Apple();
	Apple(const Vec2& position, const Size& size, const GameObjectType& tag);
	Apple(GameObject * target);

	~Apple() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;


protected:
	Texture _textureApple;
	Texture _textureRigidApple;

	string _actionName;
	float _index = 0;
};

NS_JK_END
#endif
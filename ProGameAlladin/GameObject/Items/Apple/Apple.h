#ifndef __APPLE_H__

#define __APPLE_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"

NS_JK_BEGIN

class Apple : public GameObject
{
public:
	Apple();//not use
	Apple(GameObject * target);

	~Apple() override;

	void init();
	void release();
	void update();
	void render();

	Rect getRect();

protected:
	Texture _textureApple;
	Vec2 _startPosition;

	string _actionName;
	float _index = 0;
};

NS_JK_END
#endif
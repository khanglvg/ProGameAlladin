#ifndef __FLOATGROUND_H__

#define __FLOATGROUND_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"

NS_JK_BEGIN

class FloatGround : public GameObject
{
public:
	FloatGround();//not use
	FloatGround(GameObject * target);

	~FloatGround() override;

	void init();
	void release();
	void update();
	void render();

	Rect getRect();

protected:
	Texture _textureFloatGround;
	Vec2 _startPosition;

	string _actionName;
	float _index = 0;
};

NS_JK_END
#endif
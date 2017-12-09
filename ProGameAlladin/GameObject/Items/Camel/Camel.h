#ifndef __CAMEL_H__

#define __CAMEL_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"
#include "CamelIdleState.h"
#include "CamelState.h"

NS_JK_BEGIN

class Camel : public GameObject
{
public:
	Camel();//not use
	Camel(GameObject * target);

	~Camel() override;

	void init();
	void release();
	void update();
	void render();

	void setActionName(string);
	string getActionName() const;

	Rect getRect();

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureCamel;
	Vec2 _startPosition;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	CamelState* _currentState;
};

NS_JK_END
#endif
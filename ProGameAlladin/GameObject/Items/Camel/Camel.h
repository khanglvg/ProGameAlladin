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
	Camel(const Vec2& position, const Size& size, const GameObjectType& tag);

	~Camel() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	Rect getRect() override;

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureCamel;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	CamelState* _currentState;
};

NS_JK_END
#endif
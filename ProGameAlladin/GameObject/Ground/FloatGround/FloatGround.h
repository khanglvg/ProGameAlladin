#ifndef __FLOATGROUND_H__

#define __FLOATGROUND_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"
#include "FloatGroundState.h"

NS_JK_BEGIN

class FloatGround : public GameObject
{
public:
	FloatGround();//not use
	FloatGround(const Vec2& position, const Size& size, const GameObjectType& tag);

	~FloatGround() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	Rect getRect()override;

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureFloatGround;


	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	FloatGroundState* _currentState;
};

NS_JK_END
#endif
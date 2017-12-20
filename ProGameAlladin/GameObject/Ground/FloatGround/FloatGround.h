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
	FloatGround(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);

	~FloatGround() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	Vec2 getVelocity()const;
	void setVelocity(const Vec2& velocity);

	void setVisible(const bool& isVisible);

	Rect getRect()override;

	bool isOnCollision() const;

	int getIndex();

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureFloatGround;
	bool _isCollision;

	Vec2 _lastPosition;

	GameObject* _player;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	FloatGroundState* _currentState;

	bool _isVisible = true;
};

NS_JK_END
#endif
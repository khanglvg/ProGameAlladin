#ifndef __ITEM_H__

#define __ITEM_H__
#include "../../Framework/definitions.h"
#include "../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "ItemState.h"
#include "../../pugixml/pugixml.hpp"

NS_JK_BEGIN

class Item: public GameObject
{
public:
	Item();//not use
	Item(const Vec2& position, const Size& size, const GameObjectType& tag);

	~Item() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	bool isAnimationDone();
	
	int getIndex();

	Rect getRect() override;

	bool getIsCollisionWithAladdin() const;

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureItem;

	bool _isCollisionWithAladdin;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	ItemState* _currentState;

	bool _isAnimationDone = false;

	Vec2 _startPosition;
};

NS_JK_END
#endif

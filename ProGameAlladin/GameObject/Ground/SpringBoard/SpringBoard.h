#ifndef __SPRINGBOARD_H__

#define __SPRINGBOARD_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"

NS_JK_BEGIN

class Aladdin;

class SpringBoard : public GameObject
{
public:
	SpringBoard();//not use
	SpringBoard(const Vec2& position, const Size& size, const GameObjectType& tag, Aladdin* player);

	~SpringBoard() override;

	void init()override;
	void release()override;
	void update()override;
	void render()override;

	void setActionName(string);
	string getActionName() const;

	Rect getRect()override;

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureSpringBoard;

	Aladdin* _player;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
};

NS_JK_END
#endif
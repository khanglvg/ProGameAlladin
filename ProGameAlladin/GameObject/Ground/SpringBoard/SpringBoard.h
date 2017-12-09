#ifndef __SPRINGBOARD_H__

#define __SPRINGBOARD_H__
#include "../../Framework/definitions.h"
#include "../../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../pugixml/pugixml.hpp"
#include "../../Framework/Graphics.h"
#include "SpringBoardIdleState.h"
#include "SpringBoardState.h"

NS_JK_BEGIN

class SpringBoard : public GameObject
{
public:
	SpringBoard();//not use
	SpringBoard(GameObject * target);

	~SpringBoard() override;

	void init();
	void release();
	void update();
	void render();

	void setActionName(string);
	string getActionName() const;

	Rect getRect();

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureSpringBoard;
	Vec2 _startPosition;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	SpringBoardState* _currentState;
};

NS_JK_END
#endif
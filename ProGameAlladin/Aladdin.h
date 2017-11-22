#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Rect.h"
#include "pugixml/pugixml.hpp"
#include "State/State.h"
#include "State/Idle.h"

NS_JK_BEGIN

class Aladdin: public Node
{
public:
		
	Aladdin();

	~Aladdin() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	float getMaxHeight() const;
	float getYGround() const;
	float getXGround() const;

	int getIndex() const;
	void setIndex(const int& index);
	Texture getTexture();

	std::map<string, vector<Rect>> _animations;
	
private:

	Texture _textureAla;
	float _startX = SCREEN_WIDTH / 10;
	float _startY = SCREEN_HEIGHT - 50;
	float _max = SCREEN_HEIGHT - 120;

	// --------------------------------------
	// State
	// --------------------------------------
	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	State* _currentState;
};

NS_JK_END

#endif __ALADDIN_H__


﻿#ifndef __ALADDIN_H__

#define __ALADDIN_H_

<<<<<<< HEAD:ProGameAlladin/GameObject/Aladdin.h
#include "../Framework/Texture.h"
#include "../Framework/Rect.h"
#include "../pugixml/pugixml.hpp"
#include "../State/State.h"
#include "../State/Idle.h"
#include "../Framework/RigidBody.h"
#include "GameObject.h"
=======
#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Rect.h"
#include "pugixml/pugixml.hpp"
#include "State/State.h"
#include "Framework/RigidBody.h"
#include "State/Idle.h"
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16:ProGameAlladin/Aladdin.h

NS_JK_BEGIN

class Aladdin: public GameObject
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

	Vec2 getStartPosition() const;

	std::map<string, vector<Rect>> _animations;

	Vec2 getVelocity()const;
	void setVelocity(const Vec2& velocity);

	Rect getRect() override;
	bool getisOnTheGround() const;


private:

	Texture _textureAla;
<<<<<<< HEAD:ProGameAlladin/GameObject/Aladdin.h
	//float _startX = 600;
	float _startX = SCREEN_WIDTH / 10;
=======
	Texture _textureRigid;
	float _startX = 1500;
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16:ProGameAlladin/Aladdin.h
	float _startY = SCREEN_HEIGHT - 350;
	float _max = SCREEN_HEIGHT - 120;

	// --------------------------------------
	// State
	// --------------------------------------
	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	State* _currentState;

	RigidBody* _rigidAla;
	bool isOnTheGround;

};

NS_JK_END

#endif __ALADDIN_H__


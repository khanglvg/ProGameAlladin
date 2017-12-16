#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "../Framework/Texture.h"
#include "../Framework/Rect.h"
#include "../pugixml/pugixml.hpp"
#include "../State/State.h"
#include "../State/Idle.h"
#include "../Framework/RigidBody.h"
#include "GameObject.h"
#include "Weapon.h"

NS_JK_BEGIN

class Aladdin: public GameObject
{
public:
		
	Aladdin(const Vec2& position, const Size& size);

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
	Texture getTexture() const;

	Vec2 getStartPosition() const;

	std::map<string, vector<Rect>> _animations;

	Vec2 getVelocity()const;
	void setVelocity(const Vec2& velocity) const;

	Rect getRect() override;
	bool isOnTheGround() const;
	bool isBesideTheWall() const;
	bool isBesideTheStair() const;
	bool isCollisionWithEnemy() const;
	bool isOnThePlatform() const;
	bool isOnTheRope() const;


private:
	
	Texture _textureAla;
	Texture _textureRigid;
	float _startX = 1500;
	float _startY = SCREEN_HEIGHT - 350;
	float _max = SCREEN_HEIGHT - 120;

	// --------------------------------------
	// State
	// --------------------------------------
	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	State* _currentState;

	bool _isOnTheGround;
	bool _isBesideTheStair;
	bool _isBesideTheWall;
	bool _isCollisionWithEnemy;
	bool _isOnThePlatform;
	bool _isOnTheRope;

};

NS_JK_END

#endif __ALADDIN_H__


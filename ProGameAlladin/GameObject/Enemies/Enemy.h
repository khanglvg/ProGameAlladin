#ifndef __ENEMY_H__

#define __ENEMY_H__
#include "../../Framework/definitions.h"
#include "../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "EnemyState.h"
#include "../../pugixml/pugixml.hpp"

NS_JK_BEGIN

	class Enemy: public GameObject
{
public:
	Enemy();//not use
	Enemy(GameObject * target);

	~Enemy() override;

	virtual void init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setActionName(string);
	string getActionName() const;

	//Vec2 getVelocity()const;
	//void setVelocity(const Vec2& velocity);

	virtual Rect getRect() override;

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureEnemy;
	Vec2 _startPosition;
	RigidBody *_rigid;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	EnemyState* _currentState;
};

NS_JK_END
#endif

﻿#ifndef __ENEMY_H__

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
	Enemy(const Vec2& position, const Size& size, const GameObjectType& tag,GameObject* target);

	~Enemy() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	void setActionName(string);
	string getActionName() const;

	Vec2 getVelocity()const;
	void setVelocity(const Vec2& velocity);

<<<<<<< HEAD
	bool isTargetInViewRange();
	bool isTargetInAttackRange();

	int getHealth();
	void setHealth(int newHealth);

	int getDamage();
	void setDamage(int newDamage);

	bool isRight();
	void setIsRight(bool right);

	bool isAllowMoveLeft();
	bool isAllowMoveRight();
	void allowMoveLeft(bool allow);
	void allowMoveRight(bool allow);
=======
	Rect getRect() override;
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16

	std::map<string, vector<Rect>> _animations;

protected:
	Texture _textureEnemy;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;
	EnemyState* _currentState;

	GameObject* _target;

	int _health, _damage;
	float _speed;

	// use to detect the target being near
	int _viewRange, _attackRange;
	Vec2 _distanceToTarget;

	// face look right?
	bool _isRight, _allowMoveLeft, _allowMoveRight;

	//fix foot posY
	int _footPosY;
	void setFootPosY();
};

NS_JK_END
#endif

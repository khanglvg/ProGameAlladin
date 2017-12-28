#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "../Framework/Texture.h"
#include "../Framework/Rect.h"
#include "../State/State.h"
#include "../Framework/RigidBody.h"
#include "GameObject.h"
#include "../GameObject/Weapons/Weapon.h"
#include "../State/Idle.h"
#include "../pugixml/pugixml.hpp"
NS_JK_BEGIN

class Aladdin: public GameObject
{
public:
	enum{ ENUM_LV1_SCENE, ENUM_BOSS_SCENE};
		
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

	int getNumApple() const;

	void desApple();
	void incApple();

	int getNumRuby() const;

	void desRuby();
	void incRuby();

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
	bool isOnTheFire() const;
	bool isInCamel() const;
	bool isInSpringBoard() const;
	bool isOnTheHorizontalBar() const;

	void setAllowToClimb(const bool& allow) override;
	bool isAllowToClimb() override;

	void setIsPause(const bool& pause);

	int getHealth() const;

	void desHealth();
	void incHealth();

	void setIsClimbDown(const bool& climbDown);

	void setIsDamaged(const bool& isDamaged);
	bool getIsDamaged() const;

	void setIsInviolable(const bool& isInviolable);
	bool getIsInviolable() const;

	bool isAttacked() const;

	void setIsClimb(const bool& climb);
	bool isClimb() const;

	int getEScene() const;
	void setEScene(const int& eScene);

	int getAlaLife() const;
	void desAlaLife();
	void incAlaLife();
	void setAlaLife(const int& alaLife);
	int getScore() const;

	void setCheckPoint(const Vec2& checkpoint);

	void desScore(const int& des);
	void incScore(const int& inc);
private:
	int _numApple;
	int _numRuby;
	
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

	int _health;

	GameObject* _stairInCollision;

	bool _isPause;
	bool _isClimbDown;
	bool _isClimb;

	bool _isOnTheGround;
	bool _isBesideTheStair;
	bool _isBesideTheWall;
	bool _isCollisionWithEnemy;
	bool _isOnThePlatform;
	bool _isOnTheRope;
	bool _isOnTheFire;
	bool _isInCamel;
	bool _isInSpringBoard;
	bool _isAttacked;
	bool _isOnTheHorizontalBar;
	bool _isAttackedByFlame;

	bool _isDeHealth;

	bool _isInviolable;
	bool _isDamaged;
	float _damagedTime = 0;
	float _inviolableTime = 0;
	float _inFlameTime = 0;

	Vec2 _checkPoint;

	// Sử dụng để xác định aladdin đang trong màn chơi nào. qua đó thay đổi tốc độ nhảy, chạy trong States để phù hợp với từng màn chơi 
	int _eScene;

	int _alaLife;

	int _score;
};

NS_JK_END

#endif __ALADDIN_H__


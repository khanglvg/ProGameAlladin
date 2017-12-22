#ifndef __JAFARBULLET_H_

#define __JAFARBULLET_H_
#include "../../Framework/definitions.h"
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "../../GameObject.h"

NS_JK_BEGIN
	class JafarBullet: public GameObject
{
public:
	JafarBullet(GameObject* owner, const Vec2 & position, const Size & size, GameObject* target);
	~JafarBullet();

	void init() override;
	void update() override;
	void release() override;
	void render() override;

#pragma region GET-SET
	Texture getTexture() const;
	void setVelocity(const Vec2& velocity);
	bool isCollision() const;
#pragma endregion 

	void setActionName(string);
	string getActionName() const;

	Vec2 getDistanceToAladdin() const;

private:
	GameObject* _target;

	Vec2 _distanceToAladdin;
	Vec2 _targetPosition;

	std::map<string, vector<Rect>> _animations;
	int _animationIndex;
	string _actionName;
	float _index = 0;

	bool _isDone = false;

	Texture _textureBullet;
	bool _isCollision;
	GameObject* _owner;
};
NS_JK_END
#endif


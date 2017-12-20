#ifndef __KnifeToThrow_H_

#define __KnifeToThrow_H__
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"
#include "../../Framework/definitions.h"

NS_JK_BEGIN
class KnifeToThrow : public GameObject
{
public:
	KnifeToThrow(GameObject* owner, const Vec2 & position, const Size & size);
	~KnifeToThrow();

	void init() override;
	void update() override;
	void release() override;
	void render() override;

#pragma region GET-SET
	Texture getTexture() const;
	void setVelocity(const Vec2& velocity);
	bool isCollision() const;

	void setGravityScale(const float& gravity);

	void setActionName(string);
	string getActionName() const;
#pragma endregion 

private:
	std::map<string, vector<Rect>> _animations;
	int _animationIndex;
	string _actionName;
	float _index = 0;

	bool _isDone = false;

	Texture _textureKnife;
	bool _isCollision;

	GameObject* _owner;
};
NS_JK_END
#endif


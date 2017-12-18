#ifndef __APPLETOTHROW_H_

#define __APPLETOTHROW_H__
#include "../../Framework/definitions.h"
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"

NS_JK_BEGIN
	class AppleToThrow: public GameObject
{
public:
	AppleToThrow(GameObject* owner, const Vec2 & position, const Size & size);
	~AppleToThrow();

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

private:
	std::map<string, vector<Rect>> _animations;
	int _animationIndex;
	string _actionName;
	float _index = 0;

	bool _isDone = false;

	Texture _textureApple;
	bool _isCollision;
	GameObject* _owner;
};
NS_JK_END
#endif


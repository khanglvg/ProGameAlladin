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
	KnifeToThrow(const Vec2 & position, const Size & size);
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
#pragma endregion 

private:
	std::map<int, Rect> _animations;
	int _animationIndex;
	float _index = 0;

	Texture _textureKnife;
	bool _isCollision;
};
NS_JK_END
#endif


#ifndef __CAMELBULLET_H_

#define __CAMELBULLET_H_
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"
#include "../../Framework/definitions.h"

NS_JK_BEGIN
class CamelBullet : public GameObject
{
public:
	CamelBullet(GameObject* owner, const Vec2 & position, const Size & size);
	~CamelBullet();

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
	Texture _textureKnife;
	bool _isCollision;

	Vec2 _startPosion;

	GameObject* _owner;
};
NS_JK_END
#endif


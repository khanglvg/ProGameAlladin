#ifndef __FIREGROUND_H__

#define __FIREGROUND_H__

#include "../../Framework/Node.h"
#include "../../Framework/Texture.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"

NS_JK_BEGIN

class Aladdin;

class FireGround : public GameObject
{
public:
	FireGround();

	FireGround(const Vec2 & position, const Size & size, const GameObjectType tag, Aladdin* target);

	~FireGround();

	void release() override;

	void init() override;

	void update() override;

	void render() override;

	Aladdin* getTarget();

private:
	Aladdin* _aladdin;

	Vec2 _lastColliPosition;
	Vec2 _currentColliPosition;

	int _lastFrame;
	int _currentFrame;

};

NS_JK_END

#endif __GROUND_H__


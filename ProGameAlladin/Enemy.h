#ifndef __ENEMY_H__

#define __ENEMY_H__
#include "Framework/definitions.h"
#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/RigidBody.h"

NS_JK_BEGIN

	class Enemy: public Node
{
public:
	Enemy();

	~Enemy() override;

	void init() override;
	void release() override;
	void update() override;
	void render() override;

private:
	Texture _textureEnemy;
	Vec2 _startPosition;
	RigidBody *_rigid;
};

NS_JK_END
#endif

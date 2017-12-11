﻿#ifndef __GROUND_H__

#define __GROUND_H__

#include "../../Framework/Node.h"
#include "../../Framework/Texture.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"

NS_JK_BEGIN

class Ground : public GameObject
{
public:
	Ground();

	Ground(const float& sizeX, const float& sizeY, const Vec2& rigidPosition);

	~Ground();

	void release() override;

	void init() override;

	void update() override;

	void render() override;

private:
	Texture _textureGround;
	float _startX = SCREEN_WIDTH / 10;
	float _startY = SCREEN_HEIGHT - 50;

	RigidBody* _rigidGround;
};

NS_JK_END

#endif __GROUND_H__


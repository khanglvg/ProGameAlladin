#ifndef __APPLE_H__

#define __APPLE_H__
#include "Framework/definitions.h"
#include "Framework/RigidBody.h"
#include "Framework/Node.h"
#include "Framework/Texture.h"

NS_JK_BEGIN

class Apple : public Node
{
private:
	
	RigidBody* _rigidApple;
	Texture _textureApple;


public:

	Apple();

	~Apple();

	void update() override;
	void render() override;
	void release() override;
};

NS_JK_END
#endif __APPLE_H__

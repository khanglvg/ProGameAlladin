#ifndef __APPLETOTHROW_H_

#define __APPLETOTHROW_H__
#include "../Framework/definitions.h"
#include "../Framework/Node.h"
#include "../Framework/Texture.h"
#include "../Framework/RigidBody.h"

NS_JK_BEGIN
	class AppleToThrow: public Node
{
public:
	AppleToThrow();
	~AppleToThrow();

	void init() override;
	void update() override;
	void release() override;
	void render() override;

#pragma region GET-SET
	Texture getTexture() const;
	void setVelocity(const Vec2& velocity);
	
#pragma endregion 

private:
	Texture _textureApple;
	RigidBody *_rigidApple;

};
NS_JK_END
#endif


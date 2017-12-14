#ifndef __ROPE_H__
#define __ROPE_H__
#include "../Framework/definitions.h"
#include "../../Framework/Texture.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/RigidBody.h"
#include "GameObject.h"

NS_JK_BEGIN
class Rope:public GameObject
{
public:
	Rope();
	~Rope();
	void release() override;
	void init() override;
	void update() override;
	void render() override;

private:
	Texture _textureRope;
	Texture _textureRigid;
	float _startX = SCREEN_WIDTH/10;
	float _startY = SCREEN_HEIGHT-50;
	RigidBody* _rigidRope;

	
};
NS_JK_END
#endif //! __ROPE_H__

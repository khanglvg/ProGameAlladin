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
	Rope(const Vec2& position, const Size& size, GameObjectType tag = NONE);
	~Rope();
	void release() override;
	void init() override;
	void update() override;
	void render() override;

private:
	
	Texture _textureRigid;
	

	
};
NS_JK_END
#endif //! __ROPE_H__

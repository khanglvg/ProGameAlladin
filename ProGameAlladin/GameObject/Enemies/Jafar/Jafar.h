#ifndef __JAFAR_H__

#define  __JAFAR_H__
#include "../../../Framework/definitions.h"
#include "../Enemy.h"

NS_JK_BEGIN

class Jafar: public Enemy
{
public:
	Jafar();
	Jafar(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player);
	~Jafar();
	void init() override;
	void release() override;
	void update() override;
	void render() override;

	Rect getRect() override;
private:
	Texture _textureJafar;
};

NS_JK_END
#endif //!__JAFAR_H__
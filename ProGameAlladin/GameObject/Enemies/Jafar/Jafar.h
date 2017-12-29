#ifndef __JAFAR_H__

#define  __JAFAR_H__
#include "../../../Framework/definitions.h"
#include "../Enemy.h"

NS_JK_BEGIN

class Jafar: public Enemy
{
public:
	Jafar();
	Jafar(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* target);
	~Jafar();
	void init() override;
	void release() override;
	void update() override;
	void render() override;

	bool isTransform() const;

	int getHealth() const;
	Rect getRect() override;

private:
	bool _isChecked;

	bool _isDeHeal;
	bool _isDie;

	bool _isCollisionWithApple;
	Texture _textureJafar;
	Texture _textureTransform;

	bool _isTransform;
};

NS_JK_END
#endif //!__JAFAR_H__
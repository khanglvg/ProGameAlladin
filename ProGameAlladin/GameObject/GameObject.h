#ifndef __GAMEOBJECT_H__ 
#define __GAMEOBJECT_H__

#include "../Framework/Node.h"
#include "../Framework/Texture.h"
#include "../Framework/RigidBody.h"

NS_JK_BEGIN
class GameObject:public Node
{
public:

	enum GameObjectType
	{
<<<<<<< HEAD
		None, 
		Players, 
		Enemies, 
		Apple, 
		Weapons, 
		AppleWeapon, 
		Ground, 
		Rope, 
		HorizontalBar, 
		FloatGround, 
		Springboard, 
		Camels,
		FireGround
=======
		NONE, PLAYER, ENEMIES, APPLES, WEAPONS, APPLEWEAPON, GROUND, ROPE, HORIZONTALBAR, FLOATGROUND, SPRINGBOARD, CAMELS
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	};

	GameObject();
	GameObject(const Vec2& position, const Size& size, GameObjectType tag = NONE);
	~GameObject();

	void update() override;
	void init() override; 
	void render() override;
	void release() override;


#pragma region GET-SET
	virtual Size getSize() const;
	virtual Vec2 getRigidPosition() const;

	virtual void setSize(const Size& size);
	virtual void setRigidPosition(const Vec2& position);

	GameObject::GameObjectType getTag() const;
#pragma endregion

	bool isVisible() const;

protected:
	GameObjectType _tag;

	Size _size;
	Vec2 _rigidPosition;

	Texture _textureRigid;
	RigidBody* _rigid;


	bool _isVisible;
};

NS_JK_END
#endif

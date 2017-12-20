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
		NONE, PLAYER, ENEMIES, APPLES, WEAPONS, APPLEWEAPON, GROUND, ROPE, HORIZONTALBAR, FLOATGROUND, SPRINGBOARD, CAMELS, FIREGROUND, WALL, PLATFORM, TRIGGER
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

	void setRigidTag(const string& rigidTag);
	string getRigidTag() const;

	RigidBody* getRigidBody() const;

	GameObject::GameObjectType getTag() const;

	bool isOwnerRight() const;
	void setIsOwnerRight(const bool& isOwnerRight);

	virtual void setAllowToClimb(const bool& allow);
	virtual bool isAllowToClimb();

	virtual bool isOnCollision();
#pragma endregion

	bool isVisible() const;

protected:
	bool _isAllowClimb;

	GameObjectType _tag;

	bool _isCollision;

	Texture _textureRigid;
	RigidBody* _rigid;


	bool _isVisible;

	// Hướng hiện tại của owner, true = quay bên phải
	bool _isOwnerRight;
};

NS_JK_END
#endif

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
		NONE, PLAYER, ENEMIES, APPLES, WEAPONS, APPLEWEAPON, GROUND, ROPE, HORIZONTALBAR, FLOATGROUND, SPRINGBOARD, CAMELS, FIREGROUND
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

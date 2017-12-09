#ifndef __GAMEOBJECT_H__ 
#define __GAMEOBJECT_H__

#include "../Framework/Node.h"

NS_JK_BEGIN
class GameObject:public Node
{
public:

	enum GameObjectType
	{
		None, Players, Enemies, Apple, Weapons, AppleWeapon, Ground, Rope, HorizontalBar, FloatGround, Springboard, Camels
	};

	GameObject(GameObjectType tag = None);
	~GameObject();

	//Getter, setter
	int getWidth();
	virtual void setWidth(int width);

	int getHeight();
	virtual void setHeight(int height);

	GameObject::GameObjectType getTag();

	bool isVisible();

private:
	GameObjectType _tag;
	int _width, _height;

	bool _isVisible;
};

NS_JK_END
#endif

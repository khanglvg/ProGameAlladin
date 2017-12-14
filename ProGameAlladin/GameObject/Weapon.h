#ifndef __WEAPON_H__

#define __WEAPON_H__
#include "../Framework/definitions.h"
#include "GameObject.h"

NS_JK_BEGIN
class Weapon: public GameObject
{
public:
	Weapon();
	Weapon(GameObject* owner, const Vec2& rigidPosition, const Size& rigidSize, const string& tag);
	~Weapon();

	void init() override;
	void update() override;
	void render() override;

	GameObject* getOwner() const;


private:
	Texture _textureRigid;
	GameObject* _owner;
	
};
NS_JK_END
#endif __WEAPON_H__


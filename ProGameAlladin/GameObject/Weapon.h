#ifndef __WEAPON_H__

#define __WEAPON_H__
#include "../Framework/definitions.h"
#include "GameObject.h"

NS_JK_BEGIN
class Weapon: public GameObject
{
public:
	Weapon();
	Weapon(GameObject* owner, const Vec2& rigidPosition, const Size& rigidSize, const Vec2& attackRange, const string& tag);
	~Weapon();

	void init() override;
	void update() override;
	void render() override;

	GameObject* getOwner() const;


private:
	Texture _textureRigid;
	GameObject* _owner;
	
	// khoang cach giua rigid cua weapon so voi rigid cua owner
	Vec2 _attackRange;

	
};
NS_JK_END
#endif __WEAPON_H__


#ifndef __ITEM2_H__

#define __ITEM2_H__

#include "../../Framework/Node.h"
#include "../../Framework/Texture.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/RigidBody.h"
#include "../GameObject.h"

NS_JK_BEGIN

class Aladdin;
class GameMap;

class Item2 : public GameObject
{
public:
	Item2();

	Item2(const Vec2 & position, const Size & size, const GameObjectType tag, Aladdin* target);

	~Item2();

	void release() override;

	void init() override;

	void update() override;

	void render() override;

	Aladdin* getTarget();

	void setGameMap(GameMap* map);

	std::map<string, vector<Rect>> _animations;

private:
	Aladdin* _aladdin;
	GameMap* _map;

	Texture _textureItem;

	int _animationIndex = 0;
	string _actionName;
	float _index = 0;

	bool _isIncApple;
	bool _isIncCherry;
	bool _isIncHealth;

};

NS_JK_END

#endif __GROUND_H__


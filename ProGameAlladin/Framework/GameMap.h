#ifndef __GAMEMAP_H__

#define __GAMEMAP_H_

#include "../GameObject/BackgroundLv1Scene.h"
#include "QuadTree.h"
#include "../MapReader/Tmx.h.in"
#include "Node.h"
#include "../GameObject/GameObject.h"
#include "../GameObject/Enemies/Enemy.h"
#include "../GameObject/Ground/FloatGround/FloatGround.h"
#include "../GameObject/Ground/SpringBoard/SpringBoard.h"
#include "../GameObject/Items/Camel/Camel.h"
#include "../GameObject/Items/Apple/Apple.h"

NS_JK_BEGIN

class Aladdin;

class Item2;

class GameMap
{
private:
	//don't use tileset for this game
	//std::map<int, Sprite*> _listTileSet;
	Tmx::Map *_map;
	QuadTree* _quadTree;

	Aladdin* _player;

	GameObject* _triggerLow;
	GameObject* _triggerHigh;
	GameObject* _triggerEnd;

	std::vector<BackgroundLv1Scene*> _backgroundTextures;
	std::vector<Enemy*> _listEnemies;
	std::vector<Apple*> _listApples;
	std::vector<Camel*> _listCamels;
	std::vector<FloatGround*> _listFloatGrounds;
	std::vector<SpringBoard*> _listSpringboards;
	std::vector<GameObject*> _listGround;
	std::vector<GameObject*> _listStairGround;
	std::vector<GameObject*> _listStairGroundLow;
	std::vector<GameObject*> _listStairGroundHigh;
	std::vector<GameObject*> _listRope;
	std::vector<GameObject*> _listFire;
	std::vector<GameObject*> _listHorizontalBar;
	std::vector<GameObject*> _listStop;
	std::vector<GameObject*> _listItems;

	std::vector<GameObject*> _listToRemove;

	bool _isActivedLow = false;
	bool _isActivedHigh = false;

protected:
	void checkVisibility();
	vector<GameObject*> listVisible;
	
public:
	GameMap();
	//use QuadTree* &quadTree because quadTree is init in this function
	GameMap(char* filePath, QuadTree* &quadTree, Aladdin* player);
	~GameMap();

	void init();
	void update();
	/*void Draw(Camera* camera);*/
	void draw();
	void release();

	/*Aladdin* getPlayer();*/

	vector<GameObject*> getListGround() const;
	int getWidth();
	int getHeight();

	void deleteItem(Item2* item);

	void deleteEnemy(Enemy* enemy);
};

NS_JK_END

#endif

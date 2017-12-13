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
	
class GameMap
{
private:
	//don't use tileset for this game
	//std::map<int, Sprite*> _listTileSet;
	Tmx::Map *_map;
	QuadTree* _quadTree;

	//Aladdin* _player;

	std::vector<BackgroundLv1Scene*> _backgroundTextures;
	std::vector<Enemy*> _listEnemies;
	std::vector<Apple*> _listApples;
	std::vector<Camel*> _listCamels;
	std::vector<FloatGround*> _listFloatGrounds;
	std::vector<SpringBoard*> _listSpringboards;
	std::vector<GameObject*> _listGround;
	std::vector<GameObject*> _listStairGround;
	
public:
	GameMap();
	//use QuadTree* &quadTree because quadTree is init in this function
	GameMap(char* filePath, QuadTree* &quadTree, GameObject* player);
	~GameMap();

	void init();
	void update();
	/*void Draw(Camera* camera);*/
	void draw();

	/*Aladdin* getPlayer();*/

	vector<GameObject*> getListGround() const;
	int getWidth();
	int getHeight();
};

NS_JK_END

#endif

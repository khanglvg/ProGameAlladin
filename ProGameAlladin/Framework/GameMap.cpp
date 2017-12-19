#include "GameMap.h"

#include "../GameObject/Enemies/ThinEnemy/ThinEnemy.h"
#include "../GameObject/Enemies/BigEnemy/BigEnemy.h"
#include "../GameObject/Enemies/FatEnemy/FatEnemy.h"
#include "../GameObject/Enemies/KnifeEnemy/KnifeEnemy.h"
#include "../GameObject/Enemies/HideEnemy/HideEnemy.h"
#include "../GameObject/Enemies/WallEnemy/WallEnemy.h"

US_NS_JK

GameMap::GameMap()
{}

GameMap::GameMap(char * filePath, QuadTree* &quadTree, GameObject* player)
{
	_map = new Tmx::Map();
	_map->ParseFile(filePath);

	_player = player;

	quadTree = new QuadTree(1, new Rect(-100, -300, this->getWidth()+200, this->getHeight()+400));
	_quadTree = quadTree;

	for (size_t i = 0; i < _map->GetNumLayers(); i++)
	{
		Tmx::Layer *layer = _map->GetLayers().at(i);

		if (layer->GetName() == "Tile Layer 1")
		{
			BackgroundLv1Scene* background = new BackgroundLv1Scene("Resources/AgrabahMarket1.png", 1);
			_backgroundTextures.push_back(background);
		}
		if (layer->GetName() == "Tile Layer 2")
		{
			BackgroundLv1Scene* background = new BackgroundLv1Scene("Resources/AgrabahMarket2.png", 2);
			_backgroundTextures.push_back(background);
		}
	}

	//////object here
	for (size_t i = 0; i < _map->GetNumObjectGroups(); i++)
	{
		const Tmx::ObjectGroup *objectGroup = _map->GetObjectGroup(i);

		for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
		{
			Tmx::Object *object = objectGroup->GetObjects().at(j);

			//init apple
			//if (objectGroup->GetName() == "Apple")
			//{
			//	auto apple = new Apple(Vec2(object->GetX() + object->GetWidth()/2, object->GetY() - object->GetHeight() / 2), Size(object->GetWidth(),object->GetHeight()), GameObject::APPLES);
			//	//_listApples.push_back(apple);

			//	_quadTree->insertObject(apple);
			//}

			//init float ground
			if (objectGroup->GetName() == "FloatGround")
			{
				auto *floatGround = new FloatGround(Vec2(object->GetX() + object->GetWidth()/2 + 8, object->GetY() - object->GetHeight()+5), Size(object->GetWidth(), object->GetHeight()), GameObject::FLOATGROUND);

				_listFloatGrounds.push_back(floatGround);

				//_quadTree->insertObject(floatGround);
			}

			//init Springboard
			if (objectGroup->GetName() == "Springboard")
			{
				auto *springBoard = new SpringBoard(Vec2(object->GetX(), object->GetY()), Size(object->GetWidth(), object->GetHeight()), GameObject::SPRINGBOARD);
				springBoard->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listSpringboards.push_back(springBoard);

				//_quadTree->insertObject(springBoard);
			}

			//init Enemies
			if (objectGroup->GetName() == "Enemy_1")
			{
				auto enemy = new ThinEnemy(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() - object->GetHeight() / 2 + 3), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_2")
			{
				auto enemy = new BigEnemy(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() - object->GetHeight() / 2 + 4), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_3")
			{
				auto enemy = new FatEnemy(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() - object->GetHeight() / 2 + 3), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);

			}
			if (objectGroup->GetName() == "Enemy_4_Left")
			{
				auto enemy = new KnifeEnemy(Vec2(object->GetX() + object->GetWidth(), object->GetY() - object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setScale(Vec2(-1, 1));
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_4_Right")
			{
				auto enemy = new KnifeEnemy(Vec2(object->GetX() + object->GetWidth(), object->GetY() - object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				enemy->setScale(Vec2(1, 1));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_5")
			{
				auto enemy = new HideEnemy(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() - object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "WallEnemy")
			{
				auto enemy = new WallEnemy(Vec2(object->GetX() + object->GetWidth() - 7, object->GetY() - object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::ENEMIES,player);
				enemy->setCurrentScene(player->getCurrentScene());
				_listEnemies.push_back(enemy);
			}

			//camel
			if (objectGroup->GetName() == "Camel")
			{
				auto camel = new Camel(Vec2(object->GetX() + object->GetWidth() -5, object->GetY() - object->GetHeight() / 2 + 3), Size(object->GetWidth(), object->GetHeight()), GameObject::CAMELS);
				_listCamels.push_back(camel);

				//_quadTree->insertObject(camel);
			}

			//init ground
			if (objectGroup->GetName() == "Ground")
			{
				auto gameObject = new GameObject(Vec2(object->GetX()+ object->GetWidth()/2 + 20, object->GetY() + object->GetHeight()/2), Size(object->GetWidth(), object->GetHeight()), GameObject::GROUND);
				gameObject->setRigidTag("ground");

				if(object->GetName() == "StairsGround")
				{
					gameObject->setRigidTag("stair");
					_listStairGround.push_back(gameObject);
				}
				else
				{
					_listGround.push_back(gameObject);
				}
				//_quadTree->insertObject(gameObject);
			}

			if (objectGroup->GetName() == "Platform")
			{
				auto *gameObject = new GameObject(Vec2(object->GetX() + object->GetWidth() / 2 + 15, object->GetY() + object->GetHeight() / 3), Size(object->GetWidth(), object->GetHeight()), GameObject::PLATFORM);
				gameObject->setRigidTag("platform");

				_listGround.push_back(gameObject);
			}

			if (objectGroup->GetName() == "Wall")
			{
				auto *gameObject = new GameObject(Vec2(object->GetX() + object->GetWidth() / 2 + 15, object->GetY() + object->GetHeight()/2), Size(object->GetWidth(), object->GetHeight()), GameObject::WALL);
				gameObject->setRigidTag("wall");

				_listGround.push_back(gameObject);
			}

			//init rope
			if (objectGroup->GetName() == "Rope")
			{
				auto *gameObject = new GameObject(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() + object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::ROPE);
				gameObject->setRigidTag("rope");

				_listRope.push_back(gameObject);

				//_quadTree->InsertStaticObject(gameObject);
			}

			//init FireGround
			if (objectGroup->GetName() == "Fire")
			{
				auto gameObject = new GameObject(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() + object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::FIREGROUND);
				gameObject->getRigidBody()->setDensity(0.0000000001);
				gameObject->setRigidTag("fire");
				_listFire.push_back(gameObject);
				//_quadTree->InsertStaticObject(gameObject);
			}

			//init HorizontalBar
			if (objectGroup->GetName() == "HorizontalBar")
			{
				auto *gameObject = new GameObject(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() + object->GetHeight() / 2), Size(object->GetWidth(), object->GetHeight()), GameObject::HORIZONTALBAR);

				_listHorizontalBar.push_back(gameObject);

				//_quadTree->InsertStaticObject(gameObject);
			}
		}
	}
	checkVisibility();
}

GameMap::~GameMap()
{
}

void GameMap::init()
{
	for (size_t i = 0; i < _backgroundTextures.size(); i++)
	{
		_backgroundTextures[i]->init();
	}
	for (size_t i = 0; i < _listEnemies.size(); i++)
	{
		_listEnemies[i]->init();
	}

	/*for (size_t i = 0; i < _listApples.size(); i++)
	{
		_listApples[i]->init();
	}*/
	for (size_t i = 0; i < _listCamels.size(); i++)
	{
		_listCamels[i]->init();
	}
	for (size_t i = 0; i < _listFloatGrounds.size(); i++)
	{
		_listFloatGrounds[i]->init();
	}
	for (size_t i = 0; i < _listSpringboards.size(); i++)
	{
		_listSpringboards[i]->init();
	}
	for (size_t i = 0; i < _listRope.size(); i++)
	{
		_listRope[i]->init();
	}
	for (size_t i = 0; i < _listFire.size(); i++)
	{
		_listFire[i]->init();
	}
	for (size_t i = 0; i < _listHorizontalBar.size(); i++)
	{
		_listHorizontalBar[i]->init();
	}
	for (size_t i = 0; i < listVisible.size(); i++)
	{
		listVisible[i]->init();
	}
}

void GameMap::update()
{
	checkVisibility();
	//enemies
	for (size_t i = 0; i < _listEnemies.size(); i++)
		_listEnemies[i]->update();

	//camels
	for (size_t i = 0; i < _listCamels.size(); i++)
		_listCamels[i]->update();

	//player
	//_player->update();
}

void GameMap::draw()
{
	/*don't use tileset for this game
	for (size_t i = 0; i < _map->GetNumTileLayers(); i++)
	{
	const Tmx::TileLayer *layer = _map->GetTileLayer(i);

	if (!layer->IsVisible())
	{
	continue;
	}

	for (size_t m = 0; m < layer->GetWidth(); m++)
	{
	for (size_t n = 0; n < layer->GetHeight(); n++)
	{
	int tilesetIndex = layer->GetTileTilesetIndex(m, n);
	if (tilesetIndex != -1)
	{
	const Tmx::Tileset *tileSet = _map->GetTileset(tilesetIndex);
	int tileWidth = _map->GetTileWidth();
	int tileHeight = _map->GetTileHeight();

	int tileSetWidth = tileSet->GetImage()->GetWidth() / tileWidth;
	int tileSetHeight = tileSet->GetImage()->GetHeight() / tileHeight;


	int tileID = layer->GetTileId(m, n);

	int y = tileID / tileSetWidth;
	int x = tileID - y * tileSetWidth;

	RECT sourceRECT;
	sourceRECT.top = y * tileHeight;
	sourceRECT.bottom = sourceRECT.top + tileHeight;
	sourceRECT.left = x * tileWidth;
	sourceRECT.right = sourceRECT.left + tileWidth;

	Sprite* sprite = _listTileSet[tilesetIndex];

	D3DXVECTOR3 position(m * tileWidth + tileWidth / 2, n * tileHeight + tileHeight / 2, 0);
	sprite->SetPosition(position);

	sprite->SetWidth(tileWidth);
	sprite->SetHeight(tileHeight);

	sprite->SetSourceRect(sourceRECT);
	sprite->Draw(camera);
	}
	}
	}
	}
	*/

	//////draw object here
	//apple
	//for (size_t i = 0; i < _listApples.size(); i++)
	//{
	//	//remove not visible object
	//	if (!_listApples[i]->IsVisible())
	//	{
	//		delete _listApples[i];
	//		_listApples.erase(_listApples.begin() + i);
	//		i--;
	//		continue;
	//	}

	//	//visible -> draw
	//	_listApples[i]->Draw(camera);
	//}

	////float ground
	//for (size_t i = 0; i < _listFloatGrounds.size(); i++)
	//{
	//	//remove not visible object
	//	if (!_listFloatGrounds[i]->IsVisible())
	//	{
	//		delete _listFloatGrounds[i];
	//		_listFloatGrounds.erase(_listFloatGrounds.begin() + i);
	//		i--;
	//		continue;
	//	}

	//	//visible -> draw
	//	_listFloatGrounds[i]->Draw(camera);
	//}

	////springboard
	//for (size_t i = 0; i < _listSpringboards.size(); i++)
	//{
	//	_listSpringboards[i]->Draw(camera);
	//}

	////enemies
	//for (size_t i = 0; i < _listEnemies.size(); i++)
	//{
	//	//remove not visible object
	//	if (!_listEnemies[i]->IsVisible())
	//	{
	//		delete _listEnemies[i];
	//		_listEnemies.erase(_listEnemies.begin() + i);
	//		i--;
	//		continue;
	//	}

	//	//visible -> draw
	//	_listEnemies[i]->Draw(camera);
	//}

	////camels
	//for (size_t i = 0; i < _listCamels.size(); i++)
	//{
	//	//remove not visible object
	//	if (!_listCamels[i]->IsVisible())
	//	{
	//		delete _listCamels[i];
	//		_listCamels.erase(_listCamels.begin() + i);
	//		i--;
	//		continue;
	//	}

	//	//visible -> draw
	//	_listCamels[i]->Draw(camera);
	//}

	////player
	//_player->Draw(camera);

	for (size_t i = 0; i < _backgroundTextures.size(); i++)
	{
		_backgroundTextures[i]->render();
	}
	for (size_t i = 0; i < _listEnemies.size(); i++)
	{
		_listEnemies[i]->render();
	}
	//for (size_t i = 0; i < _listApples.size(); i++)
	//{
	//	_listApples[i]->render();
	//}
	for (size_t i = 0; i < _listCamels.size(); i++)
	{
		_listCamels[i]->render();
	}
	for (size_t i = 0; i < _listFloatGrounds.size(); i++)
	{
		_listFloatGrounds[i]->render();
	}
	for (size_t i = 0; i < _listSpringboards.size(); i++)
	{
		_listSpringboards[i]->render();
	}
	for (size_t i = 0; i < _listRope.size(); i++)
	{
		_listRope[i]->render();
	}
	for (size_t i = 0; i < _listFire.size(); i++)
	{
		_listFire[i]->render();
	}
	for (size_t i = 0; i < _listHorizontalBar.size(); i++)
	{
		_listHorizontalBar[i]->render();
	}
	for (auto object : listVisible)
	{
		object->render();
	}
}

void GameMap::release()
{
	delete _map;
	delete _player;

	_quadTree->clear();
	delete _quadTree;


	for (size_t i = 0; i < _listSpringboards.size(); i++)
	{
		if (_listSpringboards[i])
			delete _listSpringboards[i];
	}
	_listSpringboards.clear();

	for (size_t i = 0; i < _listFloatGrounds.size(); i++)
	{
		if (_listFloatGrounds[i])
			delete _listFloatGrounds[i];
	}
	_listFloatGrounds.clear();

	for (size_t i = 0; i < _listCamels.size(); i++)
	{
		if (_listCamels[i])
			delete _listCamels[i];
	}
	_listCamels.clear();

	for (size_t i = 0; i < _backgroundTextures.size(); i++)
	{
		if (_backgroundTextures[i])
			delete _backgroundTextures[i];
	}
	_backgroundTextures.clear();

	for (size_t i = 0; i < _listEnemies.size(); i++)
	{
		if (_listEnemies[i])
			delete _listEnemies[i];
	}
	_listEnemies.clear();

	for (size_t i = 0; i < _listApples.size(); i++)
	{
		if (_listApples[i])
			delete _listApples[i];
	}
	_listApples.clear();

	for (size_t i = 0; i < _listRope.size(); i++)
	{
		if (_listRope[i])
			delete _listRope[i];
	}
	_listRope.clear();

	for (size_t i = 0; i < _listFire.size(); i++)
	{
		if (_listFire[i])
			delete _listFire[i];
	}
	_listFire.clear();

	for (size_t i = 0; i < _listHorizontalBar.size(); i++)
	{
		if (_listHorizontalBar[i])
			delete _listHorizontalBar[i];
	}
	_listHorizontalBar.clear();
	//for (size_t i = 0; i < listVisible.size(); i++)
	//{
	//	if (listVisible[i])
	//		delete listVisible[i];
	//}
	//listVisible.clear();
}

vector<GameObject*> GameMap::getListGround() const
{
	return _listGround;
}

//Aladdin * GameMap::getPlayer()
//{
//	return _player;
//}

int GameMap::getWidth()
{
	return _map->GetWidth() * _map->GetTileWidth();
}

int GameMap::getHeight()
{
	return _map->GetHeight() * _map->GetTileHeight();
}

void GameMap::checkVisibility()
{
	listVisible.clear();

 	_quadTree->getObjectsVisibility(listVisible, _quadTree->getVisibilityArea(_player), 3);
}
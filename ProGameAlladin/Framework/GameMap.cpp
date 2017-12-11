#include "GameMap.h"

US_NS_JK

GameMap::GameMap()
{}

GameMap::GameMap(char * filePath, QuadTree* &quadTree)
{
	_map = new Tmx::Map();
	_map->ParseFile(filePath);

	quadTree = new QuadTree(1, new Rect(0, 0, this->getWidth(), this->getHeight()));
	_quadTree = quadTree;

	for (size_t i = 0; i < _map->GetNumLayers(); i++)
	{
		Tmx::Layer *layer = _map->GetLayers().at(i);

		if (layer->GetName() == "Tile Layer 1")
		{
			BackgroundLv1Scene* background = new BackgroundLv1Scene("Resources/AgrabahMarket1.png");
			_backgroundTextures.push_back(background);
		}
		if (layer->GetName() == "Tile Layer 2")
		{
			BackgroundLv1Scene* background = new BackgroundLv1Scene("Resources/AgrabahMarket2.png");
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
			if (objectGroup->GetName() == "Apple")
			{
				Apple *apple = new Apple();
				apple->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));
				apple->setWidth(object->GetWidth());
				apple->setHeight(object->GetHeight());

				_listApples.push_back(apple);

				//_quadTree->insertObject(apple);
			}

			//init float ground
			if (objectGroup->GetName() == "FloatGround")
			{
				FloatGround *floatGround = new FloatGround();
				floatGround->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listFloatGrounds.push_back(floatGround);

				//_quadTree->InsertStaticObject(floatGround);
			}

			//init Springboard
			if (objectGroup->GetName() == "Springboard")
			{
				SpringBoard *springBoard = new SpringBoard();
				springBoard->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listSpringboards.push_back(springBoard);

				//_quadTree->InsertStaticObject(springboard);
			}

			//init Enemies
			if (objectGroup->GetName() == "Enemy_1")
			{
				Enemy *enemy = new ThinEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_2")
			{
				Enemy *enemy = new BigEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_3")
			{
				Enemy *enemy = new FatEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listEnemies.push_back(enemy);

			}
			if (objectGroup->GetName() == "Enemy_4_Left")
			{
				Enemy *enemy = new KnifeEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));
				enemy->setScale(Vec2(-1, 1));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_4_Right")
			{
				Enemy *enemy = new KnifeEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));
				enemy->setScale(Vec2(1, 1));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "Enemy_5")
			{
				Enemy *enemy = new HideEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listEnemies.push_back(enemy);
			}
			if (objectGroup->GetName() == "WallEnemy")
			{
				Enemy *enemy = new WallEnemy();
				enemy->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listEnemies.push_back(enemy);
			}

			//camel
			if (objectGroup->GetName() == "Camel")
			{
				Camel *camel = new Camel();
				camel->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));

				_listCamels.push_back(camel);

				//_quadTree->InsertStaticObject(camel);
			}

			//init ground
			if (objectGroup->GetName() == "Ground")
			{
				GameObject *gameObject = new GameObject(GameObject::GameObjectType::Ground);
				gameObject->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY()));
				gameObject->setWidth(object->GetWidth());
				gameObject->setHeight(object->GetHeight());

				_quadTree->insertObject(gameObject);
			}

			//init rope
			if (objectGroup->GetName() == "Rope")
			{
				GameObject *gameObject = new GameObject(GameObject::GameObjectType::Rope);
				gameObject->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() + object->GetHeight() / 2));
				gameObject->setWidth(object->GetWidth());
				gameObject->setHeight(object->GetHeight());

				//_quadTree->InsertStaticObject(gameObject);
			}

			//init HorizontalBar
			if (objectGroup->GetName() == "HorizontalBar")
			{
				GameObject *gameObject = new GameObject(GameObject::GameObjectType::HorizontalBar);
				gameObject->setPosition(Vec2(object->GetX() + object->GetWidth() / 2, object->GetY() + object->GetHeight() / 2));
				gameObject->setWidth(object->GetWidth());
				gameObject->setHeight(object->GetHeight());

				//_quadTree->InsertStaticObject(gameObject);
			}
		}
	}
}

GameMap::~GameMap()
{
	delete _map;
	//delete _player;

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

	for (size_t i = 0; i < _listApples.size(); i++)
	{
		_listApples[i]->init();
	}
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
}

void GameMap::update()
{
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
	for (size_t i = 0; i < _listApples.size(); i++)
	{
		_listApples[i]->render();
	}
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
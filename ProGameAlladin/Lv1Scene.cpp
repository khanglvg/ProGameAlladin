#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "GameObject/Ground/Ground.h"
#include "GameObject/Enemies/Enemy.h"
#include "AppleToThrow.h"
#include "GameObject/Wall/Wall.h"

US_NS_JK

Lv1Scene::Lv1Scene()
{
<<<<<<< HEAD
	mAladdin = new Aladdin();
	_vectNode.push_back(mAladdin);
	/*_vectNode.push_back(new BackgroundLv1Scene());
	_vectNode.push_back(new Enemy());*/
	FloatGround* enemy = new FloatGround();
	enemy->setPosition(Vec2(SCREEN_WIDTH +200, SCREEN_HEIGHT -50));
	enemy->getRect();
=======
	_vectNode.push_back(mAladdin);
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	_vectNode.push_back(new Ground());
	_vectNode.push_back(new ThinEnemy());
	_vectNode.push_back(new AppleToThrow());

<<<<<<< HEAD
	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree, mAladdin);
=======
	const auto wall_0 = new Wall(30,600,Vec2(0, 340));
	const auto wall_1 = new Wall(30,470,Vec2(1480, 200));
	const auto wall_2 = new Wall(30, 390, Vec2(2240, 500));
	const auto wall_3 = new Wall(30, 230, Vec2(2640, 290));
	const auto wall_4 = new Wall(30, 100, Vec2(2820, 620));
	const auto wall_5 = new Wall(30, 120, Vec2(2820, 235));
	const auto wall_6 = new Wall(30, 70, Vec2(3060, 470));
	const auto wall_7 = new Wall(30, 180, Vec2(3200, 90));
	const auto wall_8 = new Wall(30, 210, Vec2(3600, 230));
	const auto wall_9 = new Wall(30, 225, Vec2(4750, 110));
	const auto wall_10 = new Wall(30, 470, Vec2(4790, 460));

	_vectNode.push_back(wall_0);
	_vectNode.push_back(wall_1);
	_vectNode.push_back(wall_2);
	_vectNode.push_back(wall_3);
	_vectNode.push_back(wall_4);
	_vectNode.push_back(wall_5);
	_vectNode.push_back(wall_6);
	_vectNode.push_back(wall_7);
	_vectNode.push_back(wall_8);
	_vectNode.push_back(wall_9);
	_vectNode.push_back(wall_10);


>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	Camera::getInstance()->follow(mAladdin);
	_vectNode.push_back(Camera::getInstance());

	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree);

	for (auto ground : _gameMap->getListGround())
	{
		_vectNode.push_back(ground);
	}
}



Lv1Scene::~Lv1Scene()
{
	_gameMap->~GameMap();
}

void Lv1Scene::init()
{
	_gameMap->init();
	Scene::init();
	//for (auto object : staticobject)
	//{
	//	object->init();
	//	mQuadTree->insertObject(object);
	//}
}

void Lv1Scene::release()
{
	Scene::release();
}

void Lv1Scene::update()
{
	checkVisibility();
	Scene::update();
	_gameMap->update();
}

void Lv1Scene::render()
{
	_gameMap->draw();
	Scene::render();
	//for (auto object : listVisible)
	//{
	//	object->render();
	//}
}


void Lv1Scene::checkVisibility()
{
	listVisible.clear();

 	mQuadTree->getObjectsVisibility(listVisible, mQuadTree->getVisibilityArea(mAladdin), 1);
}

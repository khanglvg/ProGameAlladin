#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "GameObject/Ground/Ground.h"
#include "GameObject/Enemies/Enemy.h"
#include "AppleToThrow.h"
#include "GameObject/Enemies/WallEnemy/Wall2.h"
#include "GameObject/Enemies/WallEnemy/Wall3.h"
#include "GameObject/Enemies/WallEnemy/Wall4.h"
#include "GameObject/Enemies/WallEnemy/Wall5.h"
#include "GameObject/Enemies/WallEnemy/Wall6.h"
#include "GameObject/Enemies/WallEnemy/Wall7.h"
#include "GameObject/Enemies/WallEnemy/Wall8.h"
#include "GameObject/Enemies/WallEnemy/Wall9.h"
#include "GameObject/Enemies/WallEnemy/Wall10.h"

US_NS_JK

Lv1Scene::Lv1Scene()
{
	_vectNode.push_back(mAladdin);
	_vectNode.push_back(new Ground());
	_vectNode.push_back(new ThinEnemy());
	_vectNode.push_back(new AppleToThrow());

	_vectNode.push_back(new Wall2());
	_vectNode.push_back(new Wall3());
	_vectNode.push_back(new Wall4());
	_vectNode.push_back(new Wall5());
	_vectNode.push_back(new Wall6());
	_vectNode.push_back(new Wall7());
	_vectNode.push_back(new Wall8());
	_vectNode.push_back(new Wall9());
	_vectNode.push_back(new Wall10());

	Camera::getInstance()->follow(mAladdin);
	_vectNode.push_back(Camera::getInstance());

	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree);
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

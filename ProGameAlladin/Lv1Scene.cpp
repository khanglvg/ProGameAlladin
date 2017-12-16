#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "GameObject/Ground/Ground.h"
#include "GameObject/Enemies/Enemy.h"
#include "GameObject/Weapons/AppleToThrow.h"
#include "GameObject/Wall/Wall.h"
#include "GameObject/BackgroundSky.h"
#include "GameObject/Rope.h"

US_NS_JK

Lv1Scene::Lv1Scene()
{
	mAladdin = new Aladdin(Vec2(300,300),Size(25,60));
	_vectNode.push_back(mAladdin);
	mAladdin->setCurrentScene(this);
	
	_bgSky = new BackgroundSky("Resources/bg_sky.jpg", 0);
	_vectNode.push_back(_bgSky);

	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree, mAladdin);


	Camera::getInstance()->follow(mAladdin);
	_vectNode.push_back(Camera::getInstance());

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
	if(_bgSky->getPosition().getX() <= -2000)
	{
		_bgSky->setPosition(Vec2(0, 0));
	}
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

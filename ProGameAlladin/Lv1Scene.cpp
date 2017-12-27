#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "GameObject/Enemies/Enemy.h"
#include "GameObject/Weapons/AppleToThrow.h"
#include "GameObject/Wall/Wall.h"
#include "GameObject/BackgroundSky.h"
#include "Framework/Text.h"
#include "GameObject/Aladdin.h"
#include "Framework/Audio.h"
#include "Framework/Input.h"
#include "GameObject/TitleMenuScene.h"
#include "GameObject/Items/AladdinHealth.h"

US_NS_JK




Lv1Scene::Lv1Scene()
{
	
}



Lv1Scene::~Lv1Scene()
{
	_gameMap->~GameMap();
}


void Lv1Scene::init()
{


#pragma region Sound 
	_soundBackground = new Sound("Resources/Audio/AgrabahMarket.wav");
	_soundAbu = new Sound("Resources/Audio/Abu.wav");
	_soundSlash = new Sound("Resources/Audio/High Sword.wav");
	_soundSitSlash = new Sound("Resources/Audio/Low Sword.wav");
	_soundGrounding = new Sound("Resources/Audio/Aladdin Oof.wav");
	_soundPushing = new Sound("Resources/Audio/Aladdin Push.wav");
	_soundThrowing = new Sound("Resources/Audio/Object Throw.wav");
	_soundHurt = new Sound("Resources/Audio/Aladdin Hurt.wav");
	_soundAppleCollect = new Sound("Resources/Audio/Apple Collect.wav");
	_soundAppleCrush = new Sound("Resources/Audio/Apple Splash.wav");

	Audio::get()->load(_soundAbu);
	Audio::get()->load(_soundBackground);
	Audio::get()->load(_soundSlash);
	Audio::get()->load(_soundSitSlash);
	Audio::get()->load(_soundGrounding);
	Audio::get()->load(_soundPushing);
	Audio::get()->load(_soundThrowing);
	Audio::get()->load(_soundHurt);
	Audio::get()->load(_soundAppleCollect);
	Audio::get()->load(_soundAppleCrush);
	

	//Audio::get()->play(_soundBackground, true);

#pragma endregion 

	mAladdin = new Aladdin(Vec2(300, -850), Size(40, 60));
	_vectNode.push_back(mAladdin);
	mAladdin->setCurrentScene(this);


	_vectNode.push_back(new BackgroundSky("Resources/bg_sky.jpg", 0));
	//_vectNode.push_back(new Rope(Vec2(300, 440), Size(5, 220)));

	

	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree, mAladdin);


	Camera::getInstance()->follow(mAladdin);
	Camera::getInstance()->setScaleFactor(Vec2(2, 2));
	_vectNode.push_back(Camera::getInstance());
	

	_alaIcon = new TitleMenuScene("Resources/Items/items.png", Rect(339, 139, 22, 25), 3);
	_alaIcon->setType(TitleMenuScene::ALA);
	_appleIcon = new TitleMenuScene("Resources/Items/items.png", Rect(340, 17, 12, 12), 3);
	_appleIcon->setType(TitleMenuScene::APPLE);
	_appleIcon->setScale(Vec2(1.4,1.4));

	_alaIcon->setPosition(Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() + 80));
	_appleIcon->setPosition(Vec2(Camera::getInstance()->getCameraX() + 110, Camera::getInstance()->getCameraY() +86));

	_vectNode.push_back(_alaIcon);
	_vectNode.push_back(_appleIcon);

	_alaHealth = new AladdinHealth(mAladdin);
	_alaHealth->setPosition(Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() - 80));

	_vectNode.push_back(_alaHealth);

	for (auto ground : _gameMap->getListGround())
	{
		_vectNode.push_back(ground);
	}

	_gameMap->init();

	_alaLife = new Text("Arial", "3", Camera::getInstance()->getCameraX(), Camera::getInstance()->getCameraX(), 20, 30, FW_BOLD, Color(255, 255, 255, 255));
	_vectNode.push_back(_alaLife);
	//for (auto object : staticobject)
	//{
	//	object->init();
	//	mQuadTree->insertObject(object);
	//}
	Scene::init();

}

void Lv1Scene::release()
{
	_gameMap->release();
	Scene::release();
	Audio::get()->release();
}

void Lv1Scene::update()
{
	//checkVisibility();
	_alaLife->setPosition(Vec2(Camera::getInstance()->getCameraX(), Camera::getInstance()->getCameraY()));
	_gameMap->update();
	Scene::update();

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




Sound* Lv1Scene::getsoundAbu()
{
	return _soundAbu;
}

Sound* Lv1Scene::getsoundGrounding()
{
	return _soundGrounding;
}

Sound* Lv1Scene::getsoundSlash()
{
	return _soundSlash;
}

Sound* Lv1Scene::getsoundPushing()
{
	return _soundPushing;
}

Sound* Lv1Scene::getsoundThrowing()
{
	return _soundThrowing;
}

Sound* Lv1Scene::getsoundSitSlash()
{
	return _soundSitSlash;
}

Sound* Lv1Scene::getsoundHurt()
{
	return _soundHurt;
}

Sound* Lv1Scene::getsoundAppleCollect()
{
	return _soundAppleCollect;
}

Sound* Lv1Scene::getsoundAppleCrush()
{
	return _soundAppleCrush;
}


//
//void Lv1Scene::checkVisibility()
//{
//	listVisible.clear();
//
// 	mQuadTree->getObjectsVisibility(listVisible, mQuadTree->getVisibilityArea(mAladdin), 1);
//}


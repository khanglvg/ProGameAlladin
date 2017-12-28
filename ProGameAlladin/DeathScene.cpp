#include "DeathScene.h"
#include "Framework/Camera.h"
#include "Framework/GameManager.h"
#include "MenuSelectorScene.h"
US_NS_JK

DeathScene::DeathScene(Scene* oldScene): _ala(nullptr), _abu(nullptr)
{
	_oldScene = oldScene;
}

DeathScene::~DeathScene()
{
}

void DeathScene::init()
{
	_ala = new AladdinDeath("Resources/DeathScene/aladdinDeath.png", 4);
	_ala->setActionName("aladdindeath");
	_ala->setPosition(Vec2(300, 300));
	_ala->setScale(Vec2(2, 2));
	_vectNode.push_back(_ala);


	_abu = new AladdinDeath("Resources/DeathScene/aladdinDeath.png", 4);
	_abu->setActionName("abu");
	_abu->setPosition(Vec2(370, 360));
	_abu->setScale(Vec2(2, 2));
	_vectNode.push_back(_abu);

	Camera::getInstance()->setScaleFactor(Vec2(1, 1));
	Camera::getInstance()->unFollow();
	_vectNode.push_back(Camera::getInstance());

	_isInitialized = true;
	Scene::init();
}

void DeathScene::update()
{
	Scene::update();
	if(_ala->getAnimationIndex() == 25)
	{
		GameManager::getInstance()->changeScene(_oldScene);
	}
}

void DeathScene::render()
{
	Scene::render();
}

void DeathScene::release()
{
	Scene::release();
}


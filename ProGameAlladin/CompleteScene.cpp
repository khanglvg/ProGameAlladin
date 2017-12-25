#include "CompleteScene.h"
#include "GameObject/BackgroundLv1Scene.h"
#include "GameObject/BackgroundMenu.h"
#include "Framework/Camera.h"
#include "MenuSelectorScene.h"
#include "Framework/GameManager.h"
US_NS_JK

CompleteScene::CompleteScene()
{
}

CompleteScene::~CompleteScene()
{
}

void CompleteScene::init()
{
	_title = new TitleMenuScene("Resources/Complete/victory_title.png", Rect(0, 0, 232, 141),2);
	_title->setPosition(Vec2(120, 50));
	_title->setScale(Vec2(1.7, 1.7));
	_vectNode.push_back(_title);


	_ala = new AladdinAndAbu("Resources/Complete/victory_aladdin.png", 2);
	_ala->setActionName("aladdin_complete");
	_ala->setPosition(Vec2(SCREEN_WIDTH + 30, SCREEN_HEIGHT - 50));
	_ala->setScale(Vec2(-1, 1));
	_vectNode.push_back(_ala);


	_abu = new AladdinAndAbu("Resources/Complete/victory_abu.png", 2);
	_abu->setActionName("abu_complete");
	_abu->setScale(Vec2(2, 2));
	_abu->setPosition(Vec2(_ala->getPosition().getX()-100, _ala->getPosition().getY()));
	_vectNode.push_back(_abu);



	Camera::getInstance()->setScaleFactor(Vec2(1, 1));
	_vectNode.push_back(Camera::getInstance());
	Scene::init();
}

void CompleteScene::update()
{
	Scene::update();

	if(_ala->getPosition().getX() <= -100 )
	{
	//	GameManager::getInstance()->changeScene(new MenuSelector);
	}

}

void CompleteScene::render()
{
	Scene::render();
}

void CompleteScene::release()
{
	Scene::release();
}

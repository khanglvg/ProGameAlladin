#include "GameManager.h"
US_NS_JK

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::setScreenWidth(const int& width)
{
	_screenWidth = width;
}

int GameManager::getScreenWidth() const
{
	return _screenWidth;
}

void GameManager::setScreenHeight(const int& height)
{
	_screenHeight = height;
}

int GameManager::getScreenHeight() const
{
	return _screenHeight;
}

void GameManager::update()
{
	_runningScene->update();
	
}

void GameManager::init(Scene* startScene)
{
	_runningScene = startScene;
	_runningScene->init();
	
}

void GameManager::release()
{
	_runningScene->release();
}

void GameManager::render()
{
	_runningScene->render();
}

GameManager* GameManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameManager;
	}
	return _instance;
}

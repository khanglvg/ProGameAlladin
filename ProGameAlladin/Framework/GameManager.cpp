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

void GameManager::update() const
{
	_runningScene->update();
	
}

void GameManager::init(Scene* startScene)
{
	_runningScene = startScene;
	_runningScene->init();
	
}

void GameManager::release() const
{
	_runningScene->release();
}

void GameManager::render() const
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

void GameManager::changeScene(Scene* newScene)
{
	//if(newScene->getOldScene() != nullptr)
	//{
	//	// newScene = DeathScene
	//	// running = Lv1
	//	_runningScene = newScene;
	//	if(!_runningScene->isInitialized())
	//	_runningScene->init();
	//}
	//else
	//{
	//	if(_runningScene->getOldScene() != nullptr)
	//	{
	//		//running = DeathScene
	//		const auto temp = _runningScene->getOldScene();
	//		_runningScene->release();
	//		delete _runningScene;
	//		_runningScene = temp;
	//	}
	//	else
	//	{
	//		_runningScene->release();
	//		delete _runningScene;
	//		_runningScene = newScene;
	//		if (!_runningScene->isInitialized())
	//			_runningScene->init();
	//	}		
	//}

	_runningScene->release();
	delete _runningScene;
	_runningScene = newScene;
	if (!_runningScene->isInitialized())
		_runningScene->init();
}

float GameManager::getDeltaTime() const
{
	return _deltaTime;
}


void GameManager::setDeltaTime(const float& deltaTime)
{
	_deltaTime = deltaTime;
}

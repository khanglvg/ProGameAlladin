#ifndef __GAMEMANAGER_H__

#define __GAMEMANAGER_H__
#include "definitions.h"
#include "Scene.h"
NS_JK_BEGIN

class GameManager
{
	friend class Application;
public:
	
	GameManager();
	virtual ~GameManager();
	void setScreenWidth(const int& width);
	int getScreenWidth() const;
	void setScreenHeight(const int& height);
	int getScreenHeight() const;
	void update();
	void init(Scene* startScene);
	void release();
	void render();
	static GameManager* getInstance();

	float getDeltaTime() const;
	void setDeltaTime(const float& deltaTime);

private:
	static GameManager* _instance;
	int _screenWidth;
	int _screenHeight;

	float _deltaTime;
	Scene* _runningScene;
};
NS_JK_END
#endif __GAMEMANAGER_H__

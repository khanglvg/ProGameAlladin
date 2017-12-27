#ifndef __LV1SCENE_H_


#define __LV1SCENE_H_

#include "Framework/Scene.h"
#include "Framework/QuadTree.h"
#include "Framework/GameMap.h"
#include "GameObject/TitleMenuScene.h"

#include "Framework/Text.h"
#include "Framework/dxaudio.h"
#include "Framework/Sound.h"

NS_JK_BEGIN

class Aladdin;

class Lv1Scene: public Scene
{
public:
	
	Lv1Scene();
	~Lv1Scene();
	void init() override;
	void release() override;
	void update() override;
	void render() override;


	CSoundManager* _soundManager;
	Sound* getsoundAbu();
	Sound* getsoundGrounding();
	Sound* getsoundSlash();
	Sound* getsoundPushing();
	Sound* getsoundThrowing();
	Sound* getsoundSitSlash();
	Sound* getsoundHurt();
	Sound* getsoundAppleCollect();
	Sound* getsoundAppleCrush();

//protected:
//	void checkVisibility();
//	vector<Node*> listVisible;
//	vector<Node*> staticobject;

private:
	GameMap* _gameMap;
	QuadTree *mQuadTree;
	Aladdin* mAladdin;
	Node* _bgSky;
	Node* _alaHealth;


	Text* _alaLife;
	Sound*_soundBackground;
	Sound* _soundSlash;
	Sound*_soundSitSlash;
	Sound*_soundGrounding;
	Sound*_soundAbu;
	Sound*_soundPushing;
	Sound*_soundThrowing;
	Sound*_soundHurt;
	Sound*_soundAppleCollect;
	Sound*_soundAppleCrush;
	//CSound* _soundBackground;

	TitleMenuScene* _alaIcon;
	TitleMenuScene* _appleIcon;
	
};

NS_JK_END

#endif __LV1SCENE_H__


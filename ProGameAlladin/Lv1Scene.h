#ifndef __LV1SCENE_H_


#define __LV1SCENE_H_

#include "Framework/Scene.h"
#include "Framework/QuadTree.h"
#include "Framework/GameMap.h"

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
//protected:
//	void checkVisibility();
//	vector<Node*> listVisible;
//	vector<Node*> staticobject;

private:
	GameMap* _gameMap;
	QuadTree *mQuadTree;
	Aladdin* mAladdin;
	Node* _bgSky;


	Text* _alaLife;
	Sound*_soundBackground;
	Sound* _soundSlash;
	Sound*_soundGrounding;
	Sound*_soundAbu;
	Sound*_soundPushing;
	Sound*_soundThrowing;
	//CSound* _soundBackground;
	
};

NS_JK_END

#endif __LV1SCENE_H__


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
	Sound*_soundAbu;

	//static CSound*_soundAbu;

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
	
	//CSound* _soundBackground;
	
};

NS_JK_END

#endif __LV1SCENE_H__


#ifndef __LV1SCENE_H_


#define __LV1SCENE_H_

#include "Framework/Scene.h"
#include "Framework/QuadTree.h"
#include "Framework/GameMap.h"

#include "GameObject/Aladdin.h"
#include "Framework/Text.h"

NS_JK_BEGIN

class Lv1Scene: public Scene
{
public:
	Lv1Scene();
	~Lv1Scene();
	void init() override;
	void release() override;
	void update() override;
	void render() override;


//protected:
//	void checkVisibility();
//	vector<Node*> listVisible;
//	vector<Node*> staticobject;

private:
	GameMap* _gameMap;
	QuadTree *mQuadTree;
	GameObject* mAladdin;
	Node* _bgSky;

	Text* _alaLife;
	
};

NS_JK_END

#endif __LV1SCENE_H__


#ifndef __LV1SCENE_H_


#define __LV1SCENE_H_

#include "Framework/Scene.h"
#include "Framework/QuadTree.h"
#include "Framework/GameMap.h"

#include "GameObject/Aladdin.h"

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


protected:
	void checkVisibility();
	vector<Node*> listVisible;
	vector<Node*> staticobject;

private:
	GameMap* _gameMap;
	QuadTree *mQuadTree;
<<<<<<< HEAD
	GameObject* mAladdin;
=======
	Node* mAladdin = new Aladdin();
>>>>>>> ba5bb69c3100c6c6b2daac93517ca4734804ab16
	
};

NS_JK_END

#endif __LV1SCENE_H__


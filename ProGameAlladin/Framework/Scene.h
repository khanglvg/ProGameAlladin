#ifndef __SCENE_H_

#define __SCENE_H_
#include "Node.h"

NS_JK_BEGIN
class Scene
{
public:
	Scene();
	~Scene();

	virtual void init();
	virtual void update();
	virtual void release();
	virtual void render();
	
protected:
	vector<Node*> _vectNode;


};

NS_JK_END
#endif

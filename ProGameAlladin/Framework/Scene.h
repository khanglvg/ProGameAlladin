#ifndef __SCENE_H_

#define __SCENE_H_
#include "Node.h"

NS_JK_BEGIN
class Scene
{
public:
	Scene();
	~Scene();

	void Init();
	void Update();
	void Release();
	
private:
	vector<Node> _vectNode;


};

NS_JK_END
#endif

#ifndef __SCENE_H_

#define __SCENE_H_
#include "Node.h"

NS_JK_BEGIN
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual vector<Node*> getAllNodes() const;
	
	void addNode(Node* node);
	void removeNode(Node* node);
	
	Scene* getOldScene() const;

	bool isInitialized() const;
protected:
	vector<Node*> _vectNode;
	vector<Node*> _nodesToAdd;
	vector<Node*> _nodesToRemove;
	Scene* _oldScene;

	bool _isInitialized = false;
};

NS_JK_END
#endif

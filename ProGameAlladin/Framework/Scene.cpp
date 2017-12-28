#include "Scene.h"

US_NS_JK

Scene::Scene(): _oldScene(nullptr)
{
}

Scene::~Scene()
{
}

void Scene::init()
{
	for(auto node: _vectNode)
	{
		node->init();
	}
}

void Scene::update()
{
	for(auto node: _nodesToAdd)
	{
		_vectNode.push_back(node);
		node->init();
	}
	_nodesToAdd.clear();

	for (auto node : _nodesToRemove)
	{
		const auto nodeToRemove = std::find(std::begin(_vectNode), std::end(_vectNode), node);
		_vectNode.erase(nodeToRemove);
		node->release();
	}
	_nodesToRemove.clear();

	//OutputDebugString(std::to_string(_vectNode.size()).c_str());
	//OutputDebugString(" ");

	for(auto node: _vectNode)
	{
		node->update();
	}
}

void Scene::release()
{
	for(auto node: _vectNode)
	{
		node->release();
	}
}

void Scene::render()
{
	for(auto node: _vectNode)
	{
		node->render();
	}
}

vector<Node*> Scene::getAllNodes() const
{
	return _vectNode;
}

void Scene::addNode(Node* node)
{
	_nodesToAdd.push_back(node);
}

void Scene::removeNode(Node* node)
{
	_nodesToRemove.push_back(node);
}

Scene* Scene::getOldScene() const
{
	if(_oldScene != nullptr)
	{
		return _oldScene;
	}

	return nullptr;
}

bool Scene::isInitialized() const
{
	return _isInitialized;
}


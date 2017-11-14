#include "Scene.h"

US_NS_JK

Scene::Scene()
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

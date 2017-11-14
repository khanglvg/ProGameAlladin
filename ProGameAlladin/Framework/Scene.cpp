#include "Scene.h"

JaKa::Scene::Scene()
{
}

JaKa::Scene::~Scene()
{
}

void JaKa::Scene::init()
{
	for(auto node: _vectNode)
	{
		node->init();
	}
}

void JaKa::Scene::update()
{
	for(auto node: _vectNode)
	{
		node->update();
	}
}

void JaKa::Scene::release()
{
	for(auto node: _vectNode)
	{
		node->release();
	}
}

void JaKa::Scene::render()
{
	for(auto node: _vectNode)
	{
		node->render();
	}
}

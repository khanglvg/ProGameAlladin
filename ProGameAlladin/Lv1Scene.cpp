#include "Lv1Scene.h"
#include "BackgroundLv1Scene.h"

US_NS_JK

Lv1Scene::Lv1Scene()
{
	_vectNode.push_back(new Aladdin());
	_vectNode.push_back(new BackgroundLv1Scene());

}

Lv1Scene::~Lv1Scene()
{
}

void Lv1Scene::init()
{
	Scene::init();
}

void Lv1Scene::release()
{
	Scene::release();
}

void Lv1Scene::update()
{
	Scene::update();
}

void Lv1Scene::render()
{
	Scene::render();
}

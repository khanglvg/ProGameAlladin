#include "Lv1Scene.h"

JaKa::Lv1Scene::Lv1Scene()
{
	_vectNode.push_back(new Aladdin());
}

JaKa::Lv1Scene::~Lv1Scene()
{
}

void JaKa::Lv1Scene::init()
{
	Scene::init();
}

void JaKa::Lv1Scene::release()
{
	Scene::release();
}

void JaKa::Lv1Scene::update()
{
	Scene::update();
}

void JaKa::Lv1Scene::render()
{
	Scene::render();
}

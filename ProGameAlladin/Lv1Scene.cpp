#include "Lv1Scene.h"
#include "BackgroundLv1Scene.h"
#include "Framework/Camera.h"
#include "Ground.h"
#include "Enemy.h"

US_NS_JK

Lv1Scene::Lv1Scene()
{
	Aladdin *ala = new Aladdin();
	_vectNode.push_back(ala);
	_vectNode.push_back(new BackgroundLv1Scene());
	_vectNode.push_back(new Enemy());
	_vectNode.push_back(new Ground());
	Camera::getInstance()->follow(ala);
	_vectNode.push_back(Camera::getInstance());
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

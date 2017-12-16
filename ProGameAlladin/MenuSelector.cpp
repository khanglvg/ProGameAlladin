#include "MenuSelector.h"
#include "GameObject/BackgroundMenu.h"
US_NS_JK


MenuSelector::MenuSelector()
{
	_vectNode.push_back(new BackgroundMenu("Resources/Menu/backgroundMenu.png", 0));
}

MenuSelector::~MenuSelector()
{
}

void MenuSelector::init()
{
	Scene::init();
}

void MenuSelector::update()
{
	Scene::update();
}

void MenuSelector::render()
{
	Scene::render();
}

void MenuSelector::release()
{
	Scene::release();
}

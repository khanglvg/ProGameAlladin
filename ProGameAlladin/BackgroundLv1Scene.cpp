#include "BackgroundLv1Scene.h"

US_NS_JK

BackgroundLv1Scene::BackgroundLv1Scene()
{
	
}

BackgroundLv1Scene::~BackgroundLv1Scene()
{
}

void BackgroundLv1Scene::init()
{
	_textureBackground.setName("BackGround.jpg");
	_textureBackground.setSrcFile("background.jpg");

	Graphics::getInstance()->loadTexture(_textureBackground);
}

void BackgroundLv1Scene::render()
{
	Graphics::getInstance()->drawSprite(_textureBackground, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, 1000, 395));
}

#include "BackgroundLv1Scene.h"

US_NS_JK

BackgroundLv1Scene::BackgroundLv1Scene(const string& srcFile, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
}

BackgroundLv1Scene::~BackgroundLv1Scene()
{
}

void BackgroundLv1Scene::release()
{
	delete this;
}

void BackgroundLv1Scene::init()
{
	_textureBackground.setName(_srcFile + ".jpg");
	_textureBackground.setSrcFile(_srcFile);

	Graphics::getInstance()->loadTexture(_textureBackground);
}

void BackgroundLv1Scene::render()
{
	Graphics::getInstance()->drawSprite(_textureBackground, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, 4773, 689), _layer);
}

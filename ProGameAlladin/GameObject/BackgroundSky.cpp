#include "BackgroundSky.h"

US_NS_JK

BackgroundSky::BackgroundSky(const string& srcFile, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
}

BackgroundSky::~BackgroundSky()
{
}

void BackgroundSky::release()
{
	delete this;
}

void BackgroundSky::init()
{
	_textureBackground.setName(_srcFile + ".jpg");
	_textureBackground.setSrcFile(_srcFile);

	Graphics::getInstance()->loadTexture(_textureBackground);
}

void BackgroundSky::render()
{
	Graphics::getInstance()->drawSprite(_textureBackground, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0, 0, 4773, 689), _layer);
}

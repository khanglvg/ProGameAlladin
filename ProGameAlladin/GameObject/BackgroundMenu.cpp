#include "BackgroundMenu.h"
#include "../Framework/Graphics.h"
US_NS_JK

BackgroundMenu::BackgroundMenu():_layer(0)
{
}

BackgroundMenu::BackgroundMenu(const string& srcFile, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
	setScale(Vec2(2.5, 2.4));
	setPosition(Vec2(-80, -70));
}

BackgroundMenu::~BackgroundMenu()
{
}

void BackgroundMenu::init()
{
	_textureBackground.setSrcFile(_srcFile);
	_textureBackground.setName("BackgroundMenu");
	Graphics::getInstance()->loadTexture(_textureBackground);
}

void BackgroundMenu::render()
{
	Graphics::getInstance()->drawSprite(_textureBackground, 
		Vec2(0.0, 0.0), 
		getTransformMatrix(), 
		Color(255, 255, 255, 255),
		Rect(0, 0, 640, 480),
		_layer); 
}

void BackgroundMenu::release()
{
}

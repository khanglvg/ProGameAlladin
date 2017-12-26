#include "TitleMenuScene.h"
#include "../Framework/Graphics.h"
US_NS_JK

TitleMenuScene::TitleMenuScene()
{
}

TitleMenuScene::TitleMenuScene(const string& srcFile, const Rect& rect, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
	_position = Vec2(50, 0);
	_scale = Vec2(2.3, 2.3);
	_rect = rect;
}

TitleMenuScene::~TitleMenuScene()
{
}

void TitleMenuScene::init()
{
	_textureTitle.setSrcFile(_srcFile);
	_textureTitle.setName("TitleMenuScene");
	Graphics::getInstance()->loadTexture(_textureTitle);
}

void TitleMenuScene::render()
{
	Graphics::getInstance()->drawSprite(_textureTitle, 
		Vec2(0, 0),
		getTransformMatrix(), 
		Color(255, 255, 255, _alpha),
		_rect, _layer);
}

void TitleMenuScene::release()
{
}

void TitleMenuScene::setVisible(const bool& visible)
{
	if (visible == true)
	{
		_alpha = 255;
	}
	else
	{
		_alpha = 0;
	}
}

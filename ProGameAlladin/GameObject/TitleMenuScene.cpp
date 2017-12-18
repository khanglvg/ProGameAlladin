#include "TitleMenuScene.h"
#include "../Framework/Graphics.h"
US_NS_JK

TitleMenuScene::TitleMenuScene()
{
}

TitleMenuScene::TitleMenuScene(const string& srcFile, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
	_position = Vec2(50, 0);
	_scale = Vec2(2.3, 2.3);
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
		Color(255, 255, 255, 255),
		Rect(0, 0, 243, 90), _layer);
}

void TitleMenuScene::release()
{
}

#include "TitleMenuScene.h"
#include "../Framework/Graphics.h"
#include "../Framework/Camera.h"
US_NS_JK

TitleMenuScene::TitleMenuScene()
{
}

TitleMenuScene::TitleMenuScene(const string& srcFile, const Rect& rect, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;
	_position = Vec2(50, 0);
	_scale = Vec2(1, 1);
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

void TitleMenuScene::update()
{
	if (_isIcon)
	{
		if (_type == ALA)
		{
			_position = Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() + 80);
		}
		if (_type == APPLE)
		{
			_position = Vec2(Camera::getInstance()->getCameraX() + 115, Camera::getInstance()->getCameraY() + 86);
		}
		if (_type == RUBY)
		{
			_position = Vec2(Camera::getInstance()->getCameraX() + 70, Camera::getInstance()->getCameraY() + 86);
		}
	}
	
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

void TitleMenuScene::setType(const TitleType & type)
{
	_type = type;
}

void TitleMenuScene::setIcon(const bool& isIcon)
{
	if (isIcon)
		_isIcon = true;
	else
		_isIcon = false;
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

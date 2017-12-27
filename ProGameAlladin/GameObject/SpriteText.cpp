#include "SpriteText.h"
#include "../Framework/Graphics.h"
#include "../pugixml/pugixml.hpp"
#include "../Framework/Camera.h"

US_NS_JK

SpriteText::SpriteText(const string& sourceFile, const int& eValue, const int& layer)
{
	_srcFile = sourceFile;
	_value = eValue;
	_layer = layer;
	_alpha = 255;
	_type = NONE;

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Menu/text.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			const pugi::char_t* name = animation.attribute("name").value();
			vector<Rect> rects;

			for (auto rect : animation.children())
			{
				rects.push_back(Rect(rect.attribute("x").as_float(),
					rect.attribute("y").as_float(),
					rect.attribute("w").as_float(),
					rect.attribute("h").as_float()));
			}
			_animations.emplace(name, rects);
		}
	}
#pragma endregion 
}

SpriteText::~SpriteText()
{
}

void SpriteText::update()
{
	if(_type == ALA_LIFE)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() - 120, Camera::getInstance()->getCameraY() + 100);
	}

	if (_type == APPLE_UNIT)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 145, Camera::getInstance()->getCameraY() + 100);
	}

	if (_type == APPLE_TENS)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 136, Camera::getInstance()->getCameraY() + 100);
	}

	if (_type == RUBY_UNIT)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 99, Camera::getInstance()->getCameraY() + 100);
	}

	if (_type == RUBY_TENS)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 90, Camera::getInstance()->getCameraY() + 100);
	}

	if (_type == SCORE_1)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 80, Camera::getInstance()->getCameraY() - 85);
	}

	if (_type == SCORE_2)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 100, Camera::getInstance()->getCameraY() - 85);
	}

	if (_type == SCORE_3)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 120, Camera::getInstance()->getCameraY() - 85);
	}

	if (_type == SCORE_4)
	{
		_position = Vec2(Camera::getInstance()->getCameraX() + 140, Camera::getInstance()->getCameraY() - 85);
	}

}

void SpriteText::init()
{
	_texture.setSrcFile(_srcFile);
	_texture.setName("SpriteText");
	Graphics::getInstance()->loadTexture(_texture);
}

void SpriteText::render()
{
	const auto rect = _animations["Text"][_value];
	Graphics::getInstance()->drawSprite(_texture, Vec2(0.0f, 1.0f), getTransformMatrix(), Color(255, 255, 255, _alpha), rect, _layer);
}

int SpriteText::getLayer() const
{
	return _layer;
}

void SpriteText::setLayer(const int& layer)
{
	_layer = layer;
}

void SpriteText::setType(const SpriteTextType& type)
{
	_type = type;
}


void SpriteText::setVisible(const bool& visible)
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

int SpriteText::getValue() const
{
	return _value;
}

void SpriteText::setValue(const int& value)
{
	_value = value;
}

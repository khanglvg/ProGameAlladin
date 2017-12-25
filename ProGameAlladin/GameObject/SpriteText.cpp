#include "SpriteText.h"
#include "../Framework/Graphics.h"
#include "../pugixml/pugixml.hpp"

US_NS_JK

SpriteText::SpriteText(const string& sourceFile, const int& eValue, const int& layer)
{
	_srcFile = sourceFile;
	_value = eValue;
	_layer = layer;
	_alpha = 255;

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

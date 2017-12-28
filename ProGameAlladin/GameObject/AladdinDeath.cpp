#include "AladdinDeath.h"
#include "../Framework/Graphics.h"
#include "Enemies/Jafar/Jafar.h"
#include "../Framework/GameManager.h"
US_NS_JK

AladdinDeath::AladdinDeath(const string& srcTexture, const int& layer)
{
	_srcTexture = srcTexture;
	_layer = layer;



#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/DeathScene/aladdinDeath.xml");

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

AladdinDeath::~AladdinDeath()
{
}

void AladdinDeath::init()
{
	_texture.setName("AladdinDeath");
	_texture.setSrcFile(_srcTexture);
	Graphics::getInstance()->loadTexture(_texture);
}

void AladdinDeath::update()
{
}

void AladdinDeath::render()
{
	const auto rect = _animations[_actionName][_animationIndex];

	const auto expect = 0.07;
	const auto origin = Vec2(0.5f, 1.0f);


	Graphics::getInstance()->drawSprite(_texture, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, _layer);

	if (_index <= expect)
	{
		Graphics::getInstance()->drawSprite(_texture, origin, getTransformMatrix(), Color(255, 255, 255, 255), rect, _layer);
		_index += GameManager::getInstance()->getDeltaTime();
	}
	else
	{
		_index = 0;
		_animationIndex++;
		if (_animationIndex == _animations[_actionName].size())
			_animationIndex = 0;
	}
}

void AladdinDeath::release()
{
}

void AladdinDeath::setActionName(const string& actionName)
{
	_actionName = actionName;
}

string AladdinDeath::getActionName() const
{
	return _actionName;
}

int AladdinDeath::getAnimationIndex() const
{
	return _animationIndex;
}

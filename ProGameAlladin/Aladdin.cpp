#include "Aladdin.h"
#include <iostream>

US_NS_JK

Aladdin::Aladdin()
{
	setPosition(Vec2(SCREEN_WIDTH / 10, _startPosition));


#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/action2.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			const pugi::char_t* name = animation.attribute("name").value();
			vector<Rect> rects;

			for (auto rect : animation.children())
			{
				rects.push_back(Rect(	rect.attribute("x").as_float(),
										rect.attribute("y").as_float(),
										rect.attribute("w").as_float(),
										rect.attribute("h").as_float()));
			}
			_animations.emplace("a", rects);
		}
	}
#pragma endregion 
}

Aladdin::~Aladdin()
{
}

void Aladdin::init()
{
	_textureAla.setName("Aladdin.jpg");
	_textureAla.setSrcFile("Resources/ala.png");
	Graphics::getInstance()->loadTexture(_textureAla);
}

void Aladdin::release()
{
}

void Aladdin::update()
{
	_currentState->onUpdate();

	State* newState = _currentState->checkTransition();

	if (newState->checkTransition() != nullptr)
	{
		_currentState->onExit();
		delete _currentState;
		_currentState = newState->checkTransition();
		_currentState->onEnter();
	}
}

void Aladdin::render()
{
	// Vec2 là origin, được điều chỉnh trong hàm drawSprite bằng biến center để chuyển từ pixel của directx thành float (0 -> 1)
	// Left-top được xem là gốc (0.0f,0.0f)





}

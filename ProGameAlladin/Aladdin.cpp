#include "Aladdin.h"
#include <iostream>

US_NS_JK

Aladdin::Aladdin()
{


	setPosition(Vec2(SCREEN_WIDTH / 10, _startPositon));

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
			//OutputDebugString()

		}
	}
	else
		int b = -1;
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
	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	{
		if (!Input::getInstance()->isKeyDown(KEY_LEFT_ARROW))
		{
			State = "right";
			i = 0;
			setPosition(Vec2(getPosition().getX() + 3, getPosition().getY()));
		}
	}
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		if (!Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		{
			State = "left";
			i = 0;
			setPosition(Vec2(getPosition().getX() - 3, getPosition().getY()));
		}
	}
	if (Input::getInstance()->isKeyDown(KEY_SPACE))
	{
		if (jump == NONE)
		{
			jump = JUMP;
		}
	}
	if (jump == JUMP)
	{
		State = "jumping";
		setPosition(Vec2(getPosition().getX(), getPosition().getY() - 3));
		if (getPosition().getY() <= _maxJump) jump = FALL;
	}
	if (jump == FALL)
	{
		State = "jumping";
		setPosition(Vec2(getPosition().getX(), getPosition().getY() + 3));
		if (getPosition().getY() >= _startPositon) jump = NONE;
	}

}

void Aladdin::render()
{
	// Vec2 là origin, được điều chỉnh trong hàm drawSprite bằng biến center để chuyển từ pixel của directx thành float (0 -> 1)
	// Left-top được xem là gốc (0.0f,0.0f)


	if (State == "idle")
	{
		if (delta <= 8)
		{
		//	Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}

			if (i == 8 )// _vectRect.size())
			{
				i = 10;
			}

			delta++;
		}
	}

	if (State == "right")
	{

		if (delta <= 8)
		{
			setScale(Vec2(1, 1));
			//Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _throwAni[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}
			if (i == 8) //_throwAni.size())
			{
				State = "idle";
				i = 0;
			}
			delta++;
		}

	}

	if (State == "left")
	{

		setScale(Vec2(-1, 1));
		if (delta <= 8)
		{
			//Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _throwAni[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}
			if (i == 6)
			{
				State = "idle";
				i = 0;
			}
			delta++;
		}
	}

	if (State == "jumping")
	{
		setScale(Vec2(1, 1));
		if (delta <= 8)
		{
			//Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _jumpAni[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}
			if (i == 6)// _jumpAni.size())
			{
				State = "idle";
				i = 0;
			}
			delta++;
		}
	}



}

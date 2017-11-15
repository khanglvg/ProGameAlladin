#include "Aladdin.h"

US_NS_JK

Aladdin::Aladdin()
{
	// Idle1
	_vectRect.push_back(Rect(3, 9, 37, 49));
	_vectRect.push_back(Rect(47, 11, 41, 46));
	_vectRect.push_back(Rect(95, 6, 40, 51));
	_vectRect.push_back(Rect(143, 3, 44, 54));
	_vectRect.push_back(Rect(197, 6, 41, 50));
	_vectRect.push_back(Rect(250, 5, 42, 50));
	_vectRect.push_back(Rect(303, 2, 44, 52));

	// Idle2
	_vectRect.push_back(Rect(6, 83, 40, 51));
	_vectRect.push_back(Rect(51, 81, 61, 52));
	_vectRect.push_back(Rect(116, 80, 62, 53));
	_vectRect.push_back(Rect(180, 81, 41, 52));
	_vectRect.push_back(Rect(228, 81, 39, 52));
	_vectRect.push_back(Rect(275, 81, 36, 52));
	_vectRect.push_back(Rect(319, 81, 40, 52));
	_vectRect.push_back(Rect(366, 79, 40, 54));
	_vectRect.push_back(Rect(417, 61, 42, 72));
	_vectRect.push_back(Rect(465, 57, 41, 76));
	_vectRect.push_back(Rect(516, 63, 41, 70));
	_vectRect.push_back(Rect(568, 72, 41, 61));
	_vectRect.push_back(Rect(619, 80, 41, 53));
	_vectRect.push_back(Rect(668, 80, 40, 53));
	_vectRect.push_back(Rect(715, 81, 39, 52));

	// Idle3
	_vectRect.push_back(Rect(3, 165, 36, 52));
	_vectRect.push_back(Rect(46, 165, 40, 52));
	_vectRect.push_back(Rect(92, 163, 39, 54));
	_vectRect.push_back(Rect(140, 155, 37, 62));
	_vectRect.push_back(Rect(188, 151, 40, 66));
	_vectRect.push_back(Rect(238, 159, 42, 57));
	_vectRect.push_back(Rect(287, 168, 38, 48));
	_vectRect.push_back(Rect(334, 168, 39, 48));
	_vectRect.push_back(Rect(378, 168, 39, 48));
	_vectRect.push_back(Rect(427, 150, 37, 66));
	_vectRect.push_back(Rect(520, 143, 34, 73));
	_vectRect.push_back(Rect(568, 138, 38, 78));
	_vectRect.push_back(Rect(625, 155, 41, 61));
	_vectRect.push_back(Rect(666, 163, 41, 53));
	_vectRect.push_back(Rect(715, 163, 40, 53));
	_vectRect.push_back(Rect(762, 164, 39, 52));

	_throwAni.push_back(Rect(7, 235, 43, 55));
	_throwAni.push_back(Rect(57, 232, 41, 58));
	_throwAni.push_back(Rect(109, 233, 37, 57));
	_throwAni.push_back(Rect(163, 231, 46, 59));
	_throwAni.push_back(Rect(221, 235, 36, 57));
	_throwAni.push_back(Rect(268, 239, 38, 51));

	_jumpAni.push_back(Rect(8, 846, 59, 42));
	_jumpAni.push_back(Rect(75, 828, 52, 61));
	_jumpAni.push_back(Rect(137, 829, 54, 60));
	_jumpAni.push_back(Rect(203, 824, 54, 68));
	_jumpAni.push_back(Rect(269, 820, 51, 73));
	_jumpAni.push_back(Rect(336, 829, 38, 65));
	_jumpAni.push_back(Rect(390, 818, 35, 78));
	_jumpAni.push_back(Rect(448, 808, 34, 92));
	_jumpAni.push_back(Rect(504, 810, 34, 92));
	_jumpAni.push_back(Rect(564, 812, 34, 92));



	setPosition(Vec2(SCREEN_WIDTH / 10, _startPositon));

	pugi::xml_document doc;
	const auto result = doc.load_file("action2.xml");

	if (result)
	{
		for (auto a : doc.child("Animations").child("Animation"))
		{
			auto c = a.child("sprite").attribute("w");
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
	_textureAla.setSrcFile("ala.png");
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
			setPosition(Vec2(getPosition().getX() + 2, getPosition().getY()));
		}
	}
	if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	{
		if (!Input::getInstance()->isKeyUp(KEY_LEFT_ARROW))
		{
			State = "left";
			i = 0;
			setPosition(Vec2(getPosition().getX() - 2, getPosition().getY()));
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
			Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}

			if (i == _vectRect.size())
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
			Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _throwAni[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}
			if (i == _throwAni.size())
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
			Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _throwAni[i], 1);

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
			Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.3, 1.0), getTransformMatrix(), Color(255, 255, 255, 255), _jumpAni[i], 1);

			if (delta == 8)
			{
				delta = 0;
				i++;
			}
			if (i == _jumpAni.size())
			{
				State = "idle";
				i = 0;
			}
			delta++;
		}
	}



}

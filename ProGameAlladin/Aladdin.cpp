#include "Aladdin.h"

US_NS_JK

Aladdin::Aladdin()
{
	_vectRect.push_back( Rect(3, 9, 37, 49));
	_vectRect.push_back( Rect(47, 11, 41, 46));
	_vectRect.push_back( Rect(95, 6, 40, 51));
	_vectRect.push_back( Rect(143, 3, 44, 54));


	_throwAni.push_back(Rect(7, 235, 43, 55));	
	_throwAni.push_back(Rect(57, 232, 41, 58));
	_throwAni.push_back(Rect(109, 233, 37, 57));
	_throwAni.push_back(Rect(163, 231, 46, 59));
	_throwAni.push_back(Rect(221, 235, 36, 57));	
	_throwAni.push_back(Rect(268, 239, 38, 51));

	setScale(Vec2(3, 3));
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
	const auto isA = Input::getInstance()->getKey(KEY_A);
	if (isA == true)
	{
		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), _throwAni[3], 1);
	}
}

void Aladdin::render()
{
	// Vec2 là origin, được điều chỉnh trong hàm drawSprite bằng biến center để chuyển từ pixel của directx thành float (0 -> 1)
	// Left-top được xem là gốc (0.0f,0.0f)
	_isAlready = false;

	if (0<=i && i<= 10 && _isAlready == false)
	{
		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[0], 1);
		i++ ; 
		_isAlready = true;
	}

	if (11 <= i && i <= 20 && _isAlready == false)
	{
		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[1], 1);
		i ++;
		_isAlready = true;
	}
	if (21 <= i && i <= 30 && _isAlready == false)
	{
		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[2], 1);
		i ++;
		_isAlready = true;
	}
	if (31 <= i && i <= 40 && _isAlready == false)
	{
		Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.0, 0.0), getTransformMatrix(), Color(255, 255, 255, 255), _vectRect[3], 1);
		i ++;
		if (i == 40) i = 0;
		_isAlready = true;
	}
		
}
